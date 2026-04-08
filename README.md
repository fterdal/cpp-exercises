# C++ Exercises

This repo is a series of exercises to help me refresh C++ knowledge.

## Prerequisites

- CMake (3.15+)
- Conan 2.x
- C++17 compatible compiler

## Quick Start

```bash
# Build and run tests (one command!)
make test

# Run tests in watch mode (auto-reruns on file changes)
make test-watch
```

## Available Commands

| Command                   | Description                                  |
| ------------------------- | -------------------------------------------- |
| `make test`               | Build and run all tests                      |
| `make test-watch`         | Run tests in watch mode (requires `fswatch`) |
| `make test-one TEST=Name` | Run a specific test by name                  |
| `make build`              | Build the project                            |
| `make run`                | Build and run the main executable            |
| `make clean`              | Remove build directory                       |
| `make help`               | Show all available commands                  |

### Watch Mode Setup

For watch mode, install `fswatch`:

```bash
brew install fswatch
```

## Manual Build Instructions

If you prefer not to use the Makefile:

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

## Pending Tests

Tests are disabled by prefixing the test suite or test name with `DISABLED_` in the gtest `TEST()` macro. To enable a pending test, simply remove the `DISABLED_` prefix:

```cpp
// Disabled (pending)
TEST(DISABLED_AppendTests, AppendToEmptyList) { ... }

// Enabled
TEST(AppendTests, AppendToEmptyList) { ... }
```

You can also disable a single test within an active suite:

```cpp
TEST(AppendTests, DISABLED_AppendToEmptyList) { ... }
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
