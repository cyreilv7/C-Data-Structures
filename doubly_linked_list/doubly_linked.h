#ifndef DOUBLY_LINKED_H
#define DOUBLY_LINKED_H

#include <stddef.h>

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
        ~Node(){};
};

class DoublyLinked
{
    private:
        Node* head;
    public:
        DoublyLinked() { head = NULL; }
        ~DoublyLinked() {}
        void insertAtHead(int);
        void insertAtTail(int);
        void print();
        void printReverse(); // tail to head
};

#endif