# C++ Exercises

This repo is a series of exercises to help me refresh C++ knowledge.

## Prerequisites

- CMake (3.15+)
- Conan 2.x
- C++17 compatible compiler

## Build Instructions

```bash
# Install dependencies with Conan
conan install . --output-folder=build --build=missing

# Configure with CMake
cmake --preset conan-release

# Build
cmake --build build/build/Release

# Run tests
cd build/build/Release && ctest --output-on-failure
```

## Project Structure

```
.
├── CMakeLists.txt      # CMake build configuration
├── conanfile.txt       # Conan dependencies
├── src/
│   ├── main.cpp        # Main executable
│   ├── greeting.h      # Greeting function header
│   └── greeting.cpp    # Greeting function implementation
└── tests/
    └── test_greeting.cpp  # Unit tests
```
