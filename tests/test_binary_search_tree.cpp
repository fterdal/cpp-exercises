#include "binary_search_tree.h"
#include <gtest/gtest.h>
#include <string>

// ============================================================================
// Insert Tests
// ============================================================================

TEST(InsertTests, InsertIntoEmptyTree) {
  BinarySearchTree tree;
  tree.Insert(10);

  EXPECT_EQ(tree.GetSize(), 1);
  EXPECT_FALSE(tree.IsEmpty());
  EXPECT_TRUE(tree.Contains(10));
}

TEST(InsertTests, InsertMultipleElements) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  EXPECT_EQ(tree.GetSize(), 3);
  EXPECT_TRUE(tree.Contains(10));
  EXPECT_TRUE(tree.Contains(5));
  EXPECT_TRUE(tree.Contains(15));
}

TEST(InsertTests, InsertDuplicateElement) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(10);

  // Duplicates should not be inserted
  EXPECT_EQ(tree.GetSize(), 1);
}

TEST(InsertTests, InsertMaintainsBSTProperty) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(3);
  tree.Insert(7);

  // InOrder traversal should return sorted order
  EXPECT_EQ(tree.InOrder(), "3 5 7 10 15");
}

// ============================================================================
// Contains Tests
// ============================================================================

TEST(ContainsTests, ContainsInEmptyTree) {
  BinarySearchTree tree;

  EXPECT_FALSE(tree.Contains(10));
}

TEST(ContainsTests, ContainsExistingElement) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  EXPECT_TRUE(tree.Contains(5));
  EXPECT_TRUE(tree.Contains(10));
  EXPECT_TRUE(tree.Contains(15));
}

TEST(ContainsTests, ContainsNonExistingElement) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  EXPECT_FALSE(tree.Contains(1));
  EXPECT_FALSE(tree.Contains(12));
  EXPECT_FALSE(tree.Contains(99));
}

// ============================================================================
// GetMin / GetMax Tests
// ============================================================================

TEST(DISABLED_MinMaxTests, MinAndMaxOfSingleElement) {
  BinarySearchTree tree;
  tree.Insert(42);

  EXPECT_EQ(tree.GetMin(), 42);
  EXPECT_EQ(tree.GetMax(), 42);
}

TEST(DISABLED_MinMaxTests, MinAndMaxOfMultipleElements) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(3);
  tree.Insert(20);

  EXPECT_EQ(tree.GetMin(), 3);
  EXPECT_EQ(tree.GetMax(), 20);
}

TEST(DISABLED_MinMaxTests, MinAndMaxWithLeftSkewedTree) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(8);
  tree.Insert(6);
  tree.Insert(4);

  EXPECT_EQ(tree.GetMin(), 4);
  EXPECT_EQ(tree.GetMax(), 10);
}

TEST(DISABLED_MinMaxTests, MinAndMaxWithRightSkewedTree) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(12);
  tree.Insert(14);
  tree.Insert(16);

  EXPECT_EQ(tree.GetMin(), 10);
  EXPECT_EQ(tree.GetMax(), 16);
}

// ============================================================================
// GetHeight Tests
// ============================================================================

TEST(DISABLED_HeightTests, HeightOfEmptyTree) {
  BinarySearchTree tree;

  EXPECT_EQ(tree.GetHeight(), -1);
}

TEST(DISABLED_HeightTests, HeightOfSingleElement) {
  BinarySearchTree tree;
  tree.Insert(10);

  EXPECT_EQ(tree.GetHeight(), 0);
}

TEST(DISABLED_HeightTests, HeightOfBalancedTree) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  EXPECT_EQ(tree.GetHeight(), 1);
}

TEST(DISABLED_HeightTests, HeightOfUnbalancedTree) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);
  tree.Insert(40);

  EXPECT_EQ(tree.GetHeight(), 3);
}

// ============================================================================
// InOrder Tests
// ============================================================================

TEST(DISABLED_InOrderTests, InOrderEmptyTree) {
  BinarySearchTree tree;

  EXPECT_EQ(tree.InOrder(), "");
}

TEST(DISABLED_InOrderTests, InOrderSingleElement) {
  BinarySearchTree tree;
  tree.Insert(42);

  EXPECT_EQ(tree.InOrder(), "42");
}

TEST(DISABLED_InOrderTests, InOrderMultipleElements) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(3);
  tree.Insert(7);
  tree.Insert(12);
  tree.Insert(20);

  EXPECT_EQ(tree.InOrder(), "3 5 7 10 12 15 20");
}

// ============================================================================
// Remove Tests
// ============================================================================

TEST(DISABLED_RemoveTests, RemoveLeafNode) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  tree.Remove(5);

  EXPECT_EQ(tree.GetSize(), 2);
  EXPECT_FALSE(tree.Contains(5));
  EXPECT_EQ(tree.InOrder(), "10 15");
}

TEST(DISABLED_RemoveTests, RemoveNodeWithOneChild) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(3);

  tree.Remove(5);

  EXPECT_EQ(tree.GetSize(), 3);
  EXPECT_FALSE(tree.Contains(5));
  EXPECT_TRUE(tree.Contains(3));
  EXPECT_EQ(tree.InOrder(), "3 10 15");
}

TEST(DISABLED_RemoveTests, RemoveNodeWithTwoChildren) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(3);
  tree.Insert(7);

  tree.Remove(5);

  EXPECT_EQ(tree.GetSize(), 4);
  EXPECT_FALSE(tree.Contains(5));
  EXPECT_TRUE(tree.Contains(3));
  EXPECT_TRUE(tree.Contains(7));
  EXPECT_EQ(tree.InOrder(), "3 7 10 15");
}

TEST(DISABLED_RemoveTests, RemoveRoot) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  tree.Remove(10);

  EXPECT_EQ(tree.GetSize(), 2);
  EXPECT_FALSE(tree.Contains(10));
  EXPECT_EQ(tree.InOrder(), "5 15");
}

TEST(DISABLED_RemoveTests, RemoveOnlyElement) {
  BinarySearchTree tree;
  tree.Insert(10);

  tree.Remove(10);

  EXPECT_TRUE(tree.IsEmpty());
  EXPECT_EQ(tree.GetSize(), 0);
}

TEST(DISABLED_RemoveTests, RemoveNonExistingElement) {
  BinarySearchTree tree;
  tree.Insert(10);
  tree.Insert(5);

  tree.Remove(99);

  // Tree should be unchanged
  EXPECT_EQ(tree.GetSize(), 2);
  EXPECT_EQ(tree.InOrder(), "5 10");
}

TEST(DISABLED_RemoveTests, RemoveFromEmptyTree) {
  BinarySearchTree tree;

  EXPECT_NO_THROW(tree.Remove(10));
  EXPECT_TRUE(tree.IsEmpty());
}
