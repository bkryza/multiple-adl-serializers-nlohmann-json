#include <cassert>
#include <iostream>

#include "model.h"
#include "s11n.h"
#include "s11n_camel.h"

auto main(int argc, char **argv) -> int
{
    if (argc != 2) {
        std::cout << "Usage: ./main <case>\n";
        return 1;
    }

    const bool snake_case{argv[1] == std::string{"snake"}};

    ns::model::C c;

    for (int i = 10; i < 12; i++) {
        ns::model::A a{i, static_cast<float>(i), std::to_string(i)};
        c.b_values.emplace_back(ns::model::B{std::move(a)});
    }

    nlohmann::json j;

    if (snake_case) {
        j = c;
        assert(j["b_values"][0]["a_value"]["string_value"] == "10");
    }
    else {
        j = ns::s11n_camel::wrap(c);
        assert(j["bValues"][0]["aValue"]["stringValue"] == "10");
    }

    std::cout << j.dump(2) << '\n';

    return 0;
}
