#include "single_linked_list.h"

// Node constructor
Node::Node(int value) : data(value), next(nullptr) {}

// SingleLinkedList constructor
SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// SingleLinkedList destructor (stub - doesn't free memory)
SingleLinkedList::~SingleLinkedList() {
  // TODO: Implement proper cleanup
}

// Append a node to the end of the list (stub)
void SingleLinkedList::Append(int value) {
  // TODO: Implement
  if (!this->head) {
    this->head = new Node(value);
    this->tail = new Node(value);
  } else {
    this->tail->next = new Node(value);
    this->tail = this->tail->next;
  }
  this->size++;
}

// Prepend a node to the beginning of the list (stub)
void SingleLinkedList::Prepend(int value) {
  // TODO: Implement
  if (!this->head) {
    this->head = new Node(value);
    this->tail = new Node(value);
  } else {
    Node *newHead = new Node(value);
    newHead->next = this->head;
    this->head = newHead;
  }
  this->size++;
}

// Delete the node at the beginning of the list (stub)
void SingleLinkedList::DeleteHead() {
  // TODO: Implement
}

// Delete the node at the end of the list (stub)
void SingleLinkedList::DeleteTail() {
  // TODO: Implement
}

// Print the contents of each node in order (stub)
void SingleLinkedList::Print() const {
  // TODO: Implement
}

// Copy the list to a new SingleLinkedList and return it (stub)
SingleLinkedList SingleLinkedList::Copy() const {
  SingleLinkedList copy;
  // TODO: Implement
  return copy;
}

// Helper methods for testing

int SingleLinkedList::GetSize() const { return size; }

int SingleLinkedList::GetHead() const {
  if (head != nullptr) {
    return head->data;
  }
  return -1; // Stub: return -1 for empty list
}

int SingleLinkedList::GetTail() const {
  if (tail != nullptr) {
    return tail->data;
  }
  return -1; // Stub: return -1 for empty list
}

bool SingleLinkedList::IsEmpty() const { return size == 0; }
