#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    Node(int value);
};

class SingleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void Append(int value);
    void Prepend(int value);
    void DeleteHead();
    void DeleteTail();
    void Print() const;
    SingleLinkedList Copy() const;

    // Helper methods for testing
    int GetSize() const;
    int GetHead() const;
    int GetTail() const;
    bool IsEmpty() const;
};

#endif // SINGLE_LINKED_LIST_H
