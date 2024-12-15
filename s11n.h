#pragma once

#include "model.h"

#include <nlohmann/json.hpp>

namespace ns::model {
void to_json(nlohmann::json &j, const A &a)
{
    j["int_value"] = a.int_value;
    j["float_value"] = a.float_value;
    j["string_value"] = a.string_value;
}

void to_json(nlohmann::json &j, const B &b) { j["a_value"] = b.a_value; }

void to_json(nlohmann::json &j, const C &c) { j["b_values"] = c.b_values; }
} // namespace ns::model
