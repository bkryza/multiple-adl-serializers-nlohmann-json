#pragma once

#include <string>
#include <vector>

namespace ns::model {
struct A {
    int int_value;
    float float_value;
    std::string string_value;
};

struct B {
    A a_value;
};

struct C {
    std::vector<B> b_values;
};
} // namespace ns::model
