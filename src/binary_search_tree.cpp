#include "binary_search_tree.h"
#include <string>

// BSTNode constructor
BSTNode::BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}

// BinarySearchTree constructor
BinarySearchTree::BinarySearchTree() : root(nullptr), size(0) {}

// BinarySearchTree destructor
BinarySearchTree::~BinarySearchTree() {
  // TODO: Implement proper cleanup
}

void BinarySearchTree::Insert(int value) {
  // TODO: Implement
}

bool BinarySearchTree::Contains(int value) const {
  // TODO: Implement
  return false;
}

void BinarySearchTree::Remove(int value) {
  // TODO: Implement
}

int BinarySearchTree::GetMin() const {
  // TODO: Implement
  return -1;
}

int BinarySearchTree::GetMax() const {
  // TODO: Implement
  return -1;
}

int BinarySearchTree::GetHeight() const {
  // TODO: Implement
  return -1;
}

int BinarySearchTree::GetSize() const { return size; }

bool BinarySearchTree::IsEmpty() const { return size == 0; }

std::string BinarySearchTree::InOrder() const {
  // TODO: Implement
  return "";
}
