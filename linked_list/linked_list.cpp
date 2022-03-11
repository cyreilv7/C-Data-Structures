#include <iostream>
#include "linked_list.h"

// insertion into linked list
void LinkedList::insertNodeStart(int x)
{
    // note: since temp is a variable LOCAL to this function, it is
    //       a good idea to use the heap so that it persists in memory
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
    return;
}

void LinkedList::insertNodeEnd(int x)
{
    Node* newNodePtr = new Node(x);
    if (head == NULL)
    {
        head = newNodePtr;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNodePtr;
    return;
}

void LinkedList::insertNodeNth(int x, int pos)
{
    if (head == NULL || pos == 1)
    {
        insertNodeStart(x);
        return;
    }
    Node* newNodePtr = new Node(x);
    Node* temp = head;
    int i = 1;
    while (i < (pos - 1) && temp->next != NULL) // if temp->next == NULL, we've reached end of list and we insert there.
    {
        temp = temp->next;
        i++;
    }
    newNodePtr->next = temp->next;
    temp->next = newNodePtr;
    return;
}

// delete from linked list
void LinkedList::deleteNodeEnd()
{
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    delete temp->next;
    return;
}

// what if position n+1 is null? does this code work?
void LinkedList::deleteNodeNth(int pos)
{
    Node* temp = head;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < pos - 2; i++)
        temp = temp->next;
    // fix links
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    // note: CAN'T do this:
    // temp->next = temp->next->next;
    // delete temp->next
    // because you're essentially just deleting temp->next->next
    // instead, you have to remember the location of temp->next by storing it in a pointer
    // and deleting at that pointer
    return;
}

// reverse linked list
void LinkedList::reverseList()
{
/*
PSEUDOCODE:
1. Store a copy of the head and make head node point to NULL
2. Traverse linked list
3. Store a copy of current node's next node and its next node 
4. Make next node point to current node
5. Go to next node's next node and make it point to previous node
6. Repeat steps 3 - 5
*/

// INITIAL ATTEMPT
    // Node* copy_head = head;
    // Node* temp = head;
    // head->next = NULL;
    
    // // Node* previous = temp->next;
    // // Node* current = previous->next;
    // // temp->next = temp;
    // while (temp->next != NULL) // won't work b/c won't adjust link for last node
    // {
    //     Node* previous = temp->next;
    //     Node* current = previous->next;
    //     temp->next = temp;
    //     temp = previous;
    // }
    // head = temp;
    // return;

// VIDEO SOLUTION
    Node* current;
    Node* prev;
    Node* next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return;
}

// print linked list iteratively
void LinkedList::print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data;
        if (temp->next != NULL)
            std::cout << "->";
        temp = temp->next;
    }
    std::cout << std::endl;
    return;
}
