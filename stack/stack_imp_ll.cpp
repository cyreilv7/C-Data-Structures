// Linked list implementation of stack using classes

#include <stddef.h>
#include <iostream>

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
    public:
        Node* head;
        LinkedList() { head = NULL; }
        ~LinkedList() {}
        void insertAtStart(int); // corresponds to stack.push(); returns address of tail
        Node* deleteFromStart(); // corresponds to stack.pop()
        
};

class Stack
{
    private:
        LinkedList lst;
    public:
        void push(int);
        int pop();
        int top();
        bool isEmpty();
};

void LinkedList::insertAtStart(int x)
{
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return;
}

Node* LinkedList::deleteFromStart()
{
    Node* temp = head;
    head = head->next;
    return temp;
}

bool Stack::isEmpty()
{
    return lst.head == NULL;
}

void Stack::push(int x)
{
    lst.insertAtStart(x);
    return;
}

int Stack::top()
{
    return lst.head->data;
}

int Stack::pop()
{
    Node* temp = lst.deleteFromStart();
    int top = temp->data;
    delete temp;
    return top;
}

int main()
{
    Stack s;
    s.isEmpty() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl; // expected: true
    s.push(0);
    std::cout << s.top() << std::endl; // expected: 0
    s.isEmpty() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl; // expected: false
    s.pop();
    s.push(1);
    std::cout << s.pop() << std::endl; // expected: 1
    s.isEmpty() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl; // expected: true
    return 0;
}