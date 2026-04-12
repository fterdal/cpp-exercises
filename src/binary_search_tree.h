#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

struct BSTNode {
  int data;
  BSTNode *left;
  BSTNode *right;
  BSTNode(int value);
};

class BinarySearchTree {
private:
  BSTNode *root;
  int size;

public:
  BinarySearchTree();
  ~BinarySearchTree();

  void Insert(int value);
  bool Contains(int value) const;
  void Remove(int value);

  int GetMin() const;
  int GetMax() const;
  int GetHeight() const;
  int GetSize() const;
  bool IsEmpty() const;

  // Returns elements in sorted order as a string, e.g. "1 2 3"
  std::string InOrder() const;
};

#endif // BINARY_SEARCH_TREE_H
