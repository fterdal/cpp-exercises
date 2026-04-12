cmake_minimum_required(VERSION 3.15)
project(cpp_exercises CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GTest package (provided by Conan)
find_package(GTest REQUIRED)

# Main executable
add_executable(main src/main.cpp src/greeting.cpp)

# Test executable
enable_testing()
add_executable(tests
    tests/test_greeting.cpp
    tests/test_single_linked_list.cpp
    tests/test_binary_search_tree.cpp
    src/greeting.cpp
    src/single_linked_list.cpp
    src/binary_search_tree.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(tests)

# Symlink compile_commands.json to project root for linter support
add_custom_target(symlink_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
