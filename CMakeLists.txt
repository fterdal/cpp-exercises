cmake_minimum_required(VERSION 3.15)
project(cpp_exercises CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GTest package (provided by Conan)
find_package(GTest REQUIRED)

# Main executable
add_executable(main src/main.cpp src/greeting.cpp)

# Test executable
enable_testing()
add_executable(tests tests/test_greeting.cpp src/greeting.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(tests)
