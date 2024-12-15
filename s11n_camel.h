#pragma once

#include "model.h"

#include <nlohmann/json.hpp>

namespace ns::s11n_camel {
template <typename T> class wrap {
public:
    constexpr explicit wrap(const T &v) noexcept
        : value_{v}
    {
    }

    constexpr const T &get() const noexcept { return value_; }

private:
    const T &value_;
};

using ns::model::A;
using ns::model::B;
using ns::model::C;

void to_json(nlohmann::json &j, const wrap<A> &a)
{
    j["intValue"] = a.get().int_value;
    j["floatValue"] = a.get().float_value;
    j["stringValue"] = a.get().string_value;
}

void to_json(nlohmann::json &j, const wrap<B> &b)
{
    j["aValue"] = wrap<A>(b.get().a_value);
}

void to_json(nlohmann::json &j, const wrap<C> &c)
{
    std::vector<wrap<B>> b_values_wrap{
        c.get().b_values.begin(), c.get().b_values.end()};
    j["bValues"] = std::move(b_values_wrap);
}
} // namespace ns::s11n_camel
