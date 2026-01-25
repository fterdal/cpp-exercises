#include "single_linked_list.h"
#include <gtest/gtest.h>

// ============================================================================
// Append Tests
// ============================================================================

TEST(AppendTests, AppendToEmptyList) {
  SingleLinkedList list;
  list.Append(42);

  EXPECT_EQ(list.GetSize(), 1);
  EXPECT_EQ(list.GetHead(), 42);
  EXPECT_EQ(list.GetTail(), 42);
  EXPECT_FALSE(list.IsEmpty());
}

TEST(AppendTests, AppendMultipleElements) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  EXPECT_EQ(list.GetSize(), 3);
  EXPECT_EQ(list.GetHead(), 1);
  EXPECT_EQ(list.GetTail(), 3);
}

TEST(AppendTests, AppendUpdatesOnlyTail) {
  SingleLinkedList list;
  list.Append(10);
  int originalHead = list.GetHead();

  list.Append(20);
  list.Append(30);

  // Head should remain unchanged
  EXPECT_EQ(list.GetHead(), originalHead);
  // Tail should be updated
  EXPECT_EQ(list.GetTail(), 30);
}

// ============================================================================
// Prepend Tests
// ============================================================================

TEST(PrependTests, PrependToEmptyList) {
  SingleLinkedList list;
  list.Prepend(42);

  EXPECT_EQ(list.GetSize(), 1);
  EXPECT_EQ(list.GetHead(), 42);
  EXPECT_EQ(list.GetTail(), 42);
  EXPECT_FALSE(list.IsEmpty());
}

TEST(PrependTests, PrependMultipleElements) {
  SingleLinkedList list;
  list.Prepend(3);
  list.Prepend(2);
  list.Prepend(1);

  // After prepending 3, 2, 1 in that order, head should be 1
  EXPECT_EQ(list.GetSize(), 3);
  EXPECT_EQ(list.GetHead(), 1);
  EXPECT_EQ(list.GetTail(), 3);
}

TEST(PrependTests, PrependUpdatesOnlyHead) {
  SingleLinkedList list;
  list.Prepend(10);
  int originalTail = list.GetTail();

  list.Prepend(20);
  list.Prepend(30);

  // Tail should remain unchanged
  EXPECT_EQ(list.GetTail(), originalTail);
  // Head should be updated
  EXPECT_EQ(list.GetHead(), 30);
}

// ============================================================================
// DeleteHead Tests
// ============================================================================

TEST(DeleteHeadTests, DeleteHeadFromSingleElement) {
  SingleLinkedList list;
  list.Append(42);

  list.DeleteHead();

  EXPECT_TRUE(list.IsEmpty());
  EXPECT_EQ(list.GetSize(), 0);
}

TEST(DeleteHeadTests, DeleteHeadFromMultipleElements) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  list.DeleteHead();

  EXPECT_EQ(list.GetSize(), 2);
  EXPECT_EQ(list.GetHead(), 2);
  EXPECT_EQ(list.GetTail(), 3);
}

TEST(DeleteHeadTests, DeleteHeadFromEmptyList) {
  SingleLinkedList list;

  // Should not crash - just a no-op
  EXPECT_NO_THROW(list.DeleteHead());
  EXPECT_TRUE(list.IsEmpty());
}

// ============================================================================
// DeleteTail Tests
// ============================================================================

TEST(DeleteTailTests, DeleteTailFromSingleElement) {
  SingleLinkedList list;
  list.Append(42);

  list.DeleteTail();

  EXPECT_TRUE(list.IsEmpty());
  EXPECT_EQ(list.GetSize(), 0);
}

TEST(DeleteTailTests, DeleteTailFromMultipleElements) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  list.DeleteTail();

  EXPECT_EQ(list.GetSize(), 2);
  EXPECT_EQ(list.GetHead(), 1);
  EXPECT_EQ(list.GetTail(), 2);
}

TEST(DeleteTailTests, DeleteTailFromEmptyList) {
  SingleLinkedList list;

  // Should not crash - just a no-op
  EXPECT_NO_THROW(list.DeleteTail());
  EXPECT_TRUE(list.IsEmpty());
}

// ============================================================================
// Print Tests
// ============================================================================

TEST(PrintTests, PrintEmptyList) {
  SingleLinkedList list;

  testing::internal::CaptureStdout();
  list.Print();
  std::string output = testing::internal::GetCapturedStdout();

  // Empty list should print nothing or an empty indicator
  // Accept either empty string or some empty list indicator
  EXPECT_TRUE(output.empty() || output.find("empty") != std::string::npos ||
              output == "\n");
}

TEST(PrintTests, PrintSingleElement) {
  SingleLinkedList list;
  list.Append(42);

  testing::internal::CaptureStdout();
  list.Print();
  std::string output = testing::internal::GetCapturedStdout();

  // Should contain the value 42
  EXPECT_NE(output.find("42"), std::string::npos);
}

TEST(PrintTests, PrintMultipleElements) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  testing::internal::CaptureStdout();
  list.Print();
  std::string output = testing::internal::GetCapturedStdout();

  // Should contain all values in order
  // Check that 1 appears before 2, and 2 appears before 3
  size_t pos1 = output.find("1");
  size_t pos2 = output.find("2");
  size_t pos3 = output.find("3");

  EXPECT_NE(pos1, std::string::npos);
  EXPECT_NE(pos2, std::string::npos);
  EXPECT_NE(pos3, std::string::npos);
  EXPECT_LT(pos1, pos2);
  EXPECT_LT(pos2, pos3);
}

// ============================================================================
// Copy Tests
// ============================================================================

TEST(CopyTests, CopyEmptyList) {
  SingleLinkedList list;

  SingleLinkedList copy = list.Copy();

  EXPECT_TRUE(copy.IsEmpty());
  EXPECT_EQ(copy.GetSize(), 0);
}

TEST(CopyTests, CopySingleElement) {
  SingleLinkedList list;
  list.Append(42);

  SingleLinkedList copy = list.Copy();

  EXPECT_EQ(copy.GetSize(), 1);
  EXPECT_EQ(copy.GetHead(), 42);
  EXPECT_EQ(copy.GetTail(), 42);
}

TEST(CopyTests, CopyMultipleElements) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  SingleLinkedList copy = list.Copy();

  EXPECT_EQ(copy.GetSize(), 3);
  EXPECT_EQ(copy.GetHead(), 1);
  EXPECT_EQ(copy.GetTail(), 3);
}

TEST(CopyTests, CopyIsDeepCopy) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);

  SingleLinkedList copy = list.Copy();

  // Modify the copy
  copy.DeleteHead();
  copy.Append(99);

  // Original should be unchanged
  EXPECT_EQ(list.GetSize(), 3);
  EXPECT_EQ(list.GetHead(), 1);
  EXPECT_EQ(list.GetTail(), 3);

  // Copy should reflect changes
  EXPECT_EQ(copy.GetSize(), 3);
  EXPECT_EQ(copy.GetHead(), 2);
  EXPECT_EQ(copy.GetTail(), 99);
}

// ============================================================================
// Mixed Operations Tests
// ============================================================================

TEST(MixedOperationsTests, AppendAndPrependCombined) {
  SingleLinkedList list;
  list.Append(2);  // List: 2
  list.Prepend(1); // List: 1 -> 2
  list.Append(3);  // List: 1 -> 2 -> 3
  list.Prepend(0); // List: 0 -> 1 -> 2 -> 3

  EXPECT_EQ(list.GetSize(), 4);
  EXPECT_EQ(list.GetHead(), 0);
  EXPECT_EQ(list.GetTail(), 3);
}

TEST(MixedOperationsTests, DeleteAfterMultipleOperations) {
  SingleLinkedList list;
  list.Append(1);
  list.Append(2);
  list.Append(3);
  list.Prepend(0);
  // List: 0 -> 1 -> 2 -> 3

  list.DeleteHead(); // List: 1 -> 2 -> 3
  list.DeleteTail(); // List: 1 -> 2

  EXPECT_EQ(list.GetSize(), 2);
  EXPECT_EQ(list.GetHead(), 1);
  EXPECT_EQ(list.GetTail(), 2);
}
