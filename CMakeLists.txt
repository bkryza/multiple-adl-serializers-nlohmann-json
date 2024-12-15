cmake_minimum_required(VERSION 3.15)

project(multiple-adl-serializers-nlohmann-json)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    nanobench
    GIT_REPOSITORY https://github.com/martinus/nanobench.git
    GIT_TAG v4.1.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nanobench)

add_executable(main main.cc)
add_executable(benchmark benchmark.cc)

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(benchmark PRIVATE nlohmann_json::nlohmann_json nanobench)
