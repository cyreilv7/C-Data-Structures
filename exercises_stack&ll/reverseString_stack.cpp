// reverse a string using a stack

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct Node;
Node* top = NULL;

struct Node 
{
    char data;
    struct Node* next;
};

void push(char c)
{
    Node* temp = new Node;
    temp->data = c;
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
    if (isEmpty()) exit(0);
    Node* temp = top;
    top = top->next;
    return temp;
}

int main()
{
    char c[50] = "testing";
    int size = strlen(c);

    for (int i = 0; i < size; i++)
    {
        push(c[i]);
    }
    
    Node* temp = top;
    for (int i = 0; i < size; i++)
    {
        c[i] = temp->data;
        temp = temp->next;
    }
    
    // test that c[] was reversed
    for (int i = 0; i < size; i++)
    {
        cout << c[i];
    }
    cout << endl;

    return 0;
}

// note: 
// can use STL library instead of implementing your own stack ADT

// algorithm analysis:
// time-complexity: O(n)
// space-complexity: O(n)
// not very efficient in terms of space
// can get to O(1) space-complexity without stack