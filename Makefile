# Makefile for cpp-exercises
# Simplifies build, run, and test commands

BUILD_DIR := build
BUILD_TYPE := Release
BUILD_PATH := $(BUILD_DIR)/build/$(BUILD_TYPE)

# Source files to watch for changes
WATCH_FILES := src tests CMakeLists.txt

.PHONY: all build test test-watch run clean deps configure help

# Default target
all: build

# Install dependencies with Conan
deps:
	@echo "Installing dependencies with Conan..."
	conan install . --output-folder=$(BUILD_DIR) --build=missing

# Configure with CMake (runs deps if needed)
configure: 
	@if [ ! -f $(BUILD_DIR)/build/$(BUILD_TYPE)/CMakeCache.txt ]; then \
		echo "Build not configured. Running conan install and cmake configure..."; \
		$(MAKE) deps; \
		cmake --preset conan-release; \
	fi

# Build the project
build: configure
	@echo "Building project..."
	cmake --build $(BUILD_PATH)

# Run the main executable
run: build
	@echo "Running main..."
	./$(BUILD_PATH)/main

# Build and run tests
test: build
	@./$(BUILD_PATH)/tests

# Run tests in watch mode (auto-rerun on file changes)
# Requires fswatch: brew install fswatch
test-watch: build
	@echo "Watching for changes in: $(WATCH_FILES)"
	@echo "Press Ctrl+C to stop"
	@echo ""
	@# Run tests once initially
	@./$(BUILD_PATH)/tests || true
	@echo ""
	@echo "Watching for changes..."
	@fswatch -o $(WATCH_FILES) | while read; do \
		clear; \
		cmake --build $(BUILD_PATH) && ./$(BUILD_PATH)/tests || true; \
		echo ""; \
		echo "Watching for changes..."; \
	done

# Run a specific test (usage: make test-one TEST=TestName)
test-one: build
	@./$(BUILD_PATH)/tests --gtest_filter="$(TEST)"

# Clean build artifacts
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# Full rebuild from scratch
rebuild: clean all

# Show available commands
help:
	@echo "Available commands:"
	@echo "  make deps        - Install Conan dependencies"
	@echo "  make configure   - Configure CMake (auto-runs deps if needed)"
	@echo "  make build       - Build the project (default)"
	@echo "  make run         - Build and run the main executable"
	@echo "  make test        - Build and run all tests"
	@echo "  make test-watch  - Run tests in watch mode (requires fswatch)"
	@echo "  make test-one TEST=Name - Run a specific test by name (supports gtest filter patterns)"
	@echo "  make clean       - Remove build directory"
	@echo "  make rebuild     - Clean and rebuild from scratch"
	@echo "  make help        - Show this help message"
