#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

class Node
{
    public:
        int data;
        Node* next;
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        ~Node(){};
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList() { head = NULL; }
        LinkedList(Node* head) { this->head = head; }
        Node* getHead() { return head; }
        void insertNodeStart(int);
        void insertNodeEnd(int);
        void insertNodeNth(int, int);
        void deleteNodeNth(int);
        void deleteNodeEnd();
        void print();
        void reverseList();
};
#endif