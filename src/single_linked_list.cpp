#include "single_linked_list.h"
#include <iostream>

// Node constructor
Node::Node(int value) : data(value), next(nullptr) {}

// SingleLinkedList constructor
SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// SingleLinkedList destructor (stub - doesn't free memory)
SingleLinkedList::~SingleLinkedList() {
  while (!this->IsEmpty()) {
    this->DeleteHead();
  }
}

// Append a node to the end of the list (stub)
void SingleLinkedList::Append(int value) {
  if (this->IsEmpty()) {
    this->head = new Node(value);
    this->tail = this->head;
  } else {
    this->tail->next = new Node(value);
    this->tail = this->tail->next;
  }
  this->size++;
}

// Prepend a node to the beginning of the list (stub)
void SingleLinkedList::Prepend(int value) {
  if (this->IsEmpty()) {
    this->head = new Node(value);
    this->tail = this->head;
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
  if (this->IsEmpty()) {
    return;
  } else {
    Node *headNext = this->head->next;
    if (this->head == this->tail) {
      this->tail = nullptr;
    }
    delete this->head;
    this->head = headNext;
    this->size--;
  }
}

// Delete the node at the end of the list (stub)
void SingleLinkedList::DeleteTail() {
  if (this->IsEmpty()) {
    return;
  } else if (!this->head->next) {
    delete this->head;
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    return;
  }
  Node *ptr = this->head;
  while (ptr->next->next) {
    ptr = ptr->next;
  }
  delete ptr->next;
  this->tail = ptr;
  this->size--;
}

// Print the contents of each node in order (stub)
void SingleLinkedList::Print() const {
  if (!this->head) {
    std::cout << "empty\n";
  } else {
    Node *ptr = this->head;
    while (ptr) {
      std::cout << ptr->data << " -> ";
      ptr = ptr->next;
    }
    std::cout << "end\n";
  }
}

// Copy the list to a new SingleLinkedList and return it (stub)
SingleLinkedList SingleLinkedList::Copy() const {
  SingleLinkedList copy;
  Node *ptr = this->head;
  while (ptr) {
    copy.Append(ptr->data);
    ptr = ptr->next;
  }
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

bool SingleLinkedList::HeadIsTail() const { return head == tail; }
