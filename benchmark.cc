#define ANKERL_NANOBENCH_IMPLEMENT

#include <nanobench.h>

#include "model.h"
#include "s11n.h"
#include "s11n_camel.h"

auto build_model()
{
    ns::model::C m;
    for (int i = 0; i < 1000; i++) {
        ns::model::A a{i, (float)i, std::to_string(i)};
        m.b_values.emplace_back(ns::model::B{std::move(a)});
    }
    return m;
}

auto main() -> int
{
    nlohmann::json j1, j2;

    const auto c = build_model();

    ankerl::nanobench::Bench().run("Default s11n", [&] {
        j1 = c;
        ankerl::nanobench::doNotOptimizeAway(j1);
    });

    ankerl::nanobench::Bench().run("Camel s11n", [&] {
        j2 = ns::s11n_camel::wrap(c);
        ankerl::nanobench::doNotOptimizeAway(j2);
    });

    assert(j1["b_values"][0]["a_value"]["string_value"] ==
        j2["bValues"][0]["aValue"]["stringValue"]);
}