// stack implementation of reversing a linked list
#include <stack>
#include <iostream>
using namespace std;

typedef struct Node;
struct Node 
{
    int data;
    Node* next;
};

// linked list implementation
void insert(Node** head, int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
    return;
}

void print(Node* head)
{
    if (head == NULL)
        return;
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

// reverse function using stack
void reverse(Node** head)
{
    // if the value of head == NULL, not if 
    // what it points to is NULL
    if (*head == NULL)
        return;
    stack<Node*> s;
    Node* temp = *head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    *head = s.top();
    s.pop();
    temp = *head;
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

void reversePrint(Node* head)
{
    stack<int> s;
    Node* temp = head;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    while (s.size() > 1)
    {
        cout << s.top() << " -> ";
        s.pop();
    }
    cout << s.top() << endl;
    s.pop();
    return;
}

// just for fun/review: using implicit stack
void reversePrintRecursive(Node* head)
{
    if (head == NULL)
        return;
    reversePrintRecursive(head->next);
    cout << head->data << " ";
    return;
}

void reverseRecursive(Node* ptr, Node** head)
{
    if (ptr->next == NULL)
    {
        *head = ptr;
        return;
    }
    reverseRecursive(ptr->next, head);
    ptr->next->next = ptr;
    ptr->next = NULL;
    return;
}

int main()
{
    Node* head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    print(head);
    // reversePrint(head);
    // reversePrintRecursive(head);
    reverseRecursive(head, &head);
    print(head);
    
    reverse(&head);
    print(head);
}