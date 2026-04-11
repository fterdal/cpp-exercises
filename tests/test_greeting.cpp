#include "greeting.h"
#include <array>
#include <cstdlib>
#include <gtest/gtest.h>
#include <memory>
#include <string>

// Test that getGreeting() returns "Hello, World!"
TEST(GreetingTest, ReturnsHelloWorld) {
  EXPECT_EQ(getGreeting(), "Hello, World!");
}

// Test that the main executable outputs "Hello, World!" and exits successfully
TEST(MainExecutableTest, OutputsHelloWorldAndExitsSuccessfully) {
  // Run the main executable and capture output
  std::array<char, 128> buffer;
  std::string result;

  // Use popen to run the executable and capture stdout
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("./main 2>&1", "r"),
                                                pclose);

  ASSERT_NE(pipe, nullptr) << "Failed to run main executable";

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  // Remove trailing newline if present
  if (!result.empty() && result.back() == '\n') {
    result.pop_back();
  }

  EXPECT_EQ(result, "Hello, World!");
}
