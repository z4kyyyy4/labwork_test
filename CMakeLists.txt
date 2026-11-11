cmake_minimum_required(VERSION 3.14)
project(labwork_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(quadratic quadratic.cpp)

add_executable(app main.cpp)
target_link_libraries(app quadratic)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(quadratic_tests test_quadratic.cpp)
target_link_libraries(quadratic_tests quadratic GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(quadratic_tests)