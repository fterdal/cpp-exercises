#include "binary_search_tree.h"
#include <iostream>
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
  if (this->IsEmpty()) {
    this->root = new BSTNode(value);
    this->size++;
    return;
  }
  BSTNode *nodePtr = this->root;
  while (nodePtr) {
    if (nodePtr->data == value) { return; }
    bool lessThan = value < nodePtr->data;
    BSTNode *leftNode = nodePtr->left;
    BSTNode *rightNode = nodePtr->right;
    if (lessThan && leftNode) {
      nodePtr = nodePtr->left;
    } else if (lessThan && !leftNode) {
      nodePtr->left = new BSTNode(value);
      this->size++;
      return;
    } else if (!lessThan && rightNode) {
      nodePtr = nodePtr->right;
    } else if (!lessThan && !rightNode) {
      nodePtr->right = new BSTNode(value);
      this->size++;
    }
  }
}

bool BinarySearchTree::Contains(int value) const {
  if (this->IsEmpty()) { return false; }
  BSTNode *nodePtr = this->root;
  while (nodePtr) {
    if (nodePtr->data == value) { return true; }
    if (value < nodePtr->data) {
      nodePtr = nodePtr->left;
    } else {
      nodePtr = nodePtr->right;
    }
  }
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

// Helper function that takes in a node and returns an array in ascending
// sorted order, traverses recursively in-order
std::string sortedNodes(BSTNode *node, std::string acc) {
  if (!node) { return acc; }
  std::string left = "";
  if (node->left) {
    left = sortedNodes(node->left, acc);
  }
  std::string right = "";
  if (node->right) {
    right = sortedNodes(node->right, acc);
  }
  std::string leftAndRoot = left.append(std::to_string(node->data)).append(" ");
  return leftAndRoot.append(right);
}

std::string trimFinalWhitespace(std::string string) {
  int length = string.length();
  if (!length) return string;
  if (string[length-1] == ' ') {
    return string.substr(0, length-1);
  } else {
    return string;
  }
}

std::string BinarySearchTree::InOrder() const {
  if (this->IsEmpty()) { return ""; }
  return trimFinalWhitespace(sortedNodes(this->root, ""));
}

