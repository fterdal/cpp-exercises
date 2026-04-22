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

// HELPER FUNCTIONS
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

int heightHelper(BSTNode *node) {
  std::cout << "heightHelper node" << node->data << "\n";
  if (!node) return 0;
  int leftHeight = 0;
  int rightHeight = 0;
  if (node->left) {
    leftHeight = heightHelper(node->left);
  }
  if (node->right) {
    rightHeight = heightHelper(node->right);
  }
  if (leftHeight > rightHeight) { return 1 + leftHeight; }
  return 1 + rightHeight;
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
  // Strategy: Loop with current and previous, where previous is always the parent of
  // current. When current matches value, set previous->left/right to nullptr and delete current.
  BSTNode *prev = nullptr;
  BSTNode *curr = this->root;
  while (curr) {
    if (curr->data == value) {
      // Found a match!
      if (prev) {
        BSTNode *currLeft = curr->left;
        BSTNode *currRight = curr->right;

        if (!currLeft && !currRight) {
          // CASE 1: current is a leaf - no children
          if (prev->right == curr) { prev->right = nullptr; }
          else if (prev->left == curr) { prev->left = nullptr; }
        } else if (currLeft && currRight) {
          // CASE 2: current has two children, must rotate
          // TODO
          return;
        } else if (currLeft) {
          // CASE 3: Only left child
          if (prev->right == curr) { prev->right = currLeft; }
          else if (prev->left == curr) { prev->left = currLeft; }
        } else {
          // CASE 4: Only right child
          if (prev->right == curr) { prev->right = currRight; }
          else if (prev->left == curr) { prev->left = currRight; }
        }
      } else {
        // TODO. In this case, we're deleting the root.
        delete curr;
        this->root = nullptr;
        this->size = 0;
      }
      // Delete the current node and decrement the size
      delete curr;
      this->size--;
      return;
    } else {
      if (value < curr->data) {
        prev = curr;
        curr = curr->left;
      } else {
        prev = curr;
        curr = curr->right;
      }
    }
  }
}

int BinarySearchTree::GetMin() const {
  if (this->IsEmpty()) { return -1; }
  BSTNode *nodePtr = this->root;
  while (nodePtr) {
    if (!nodePtr->left) { return nodePtr->data; }
    nodePtr = nodePtr->left;
  }
  return -1;
}

int BinarySearchTree::GetMax() const {
  if (this->IsEmpty()) { return -1; }
  BSTNode *nodePtr = this->root;
  while (nodePtr) {
    if (!nodePtr->right) { return nodePtr->data; }
    nodePtr = nodePtr->right;
  }
  return -1;
}

int BinarySearchTree::GetHeight() const {
  if (this->IsEmpty()) { return -1; }
  return heightHelper(this->root) - 1;
}

int BinarySearchTree::GetSize() const { return size; }

bool BinarySearchTree::IsEmpty() const { return size == 0; }


std::string BinarySearchTree::InOrder() const {
  if (this->IsEmpty()) { return ""; }
  return trimFinalWhitespace(sortedNodes(this->root, ""));
}


