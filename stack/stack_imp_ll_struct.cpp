// Simple linked list implementation of stack using a struct instead of a class

#include <iostream>
using namespace std;

typedef struct Node;
Node* top = NULL;

struct Node 
{
    int data;
    struct Node* next;
};

void push(int x)
{
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    return;
}

bool isEmpty()
{
    return top == NULL;
}

Node* pop()
{
    if (isEmpty()) return;
    Node* temp = top;
    top = top->next;
    return temp;
}

int main()
{
    push(5);
    cout << top->data << endl;
    cout << pop()->data << endl;
    isEmpty() ? cout << "empty" : cout << "not empty";
    cout << endl;
    pop();
    return 0;
}


