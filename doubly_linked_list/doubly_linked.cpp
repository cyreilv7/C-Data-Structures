#include "doubly_linked.h"
#include <iostream>

void DoublyLinked::insertAtHead(int x)
{
    Node* newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
}

void DoublyLinked::insertAtTail(int x)
{
    Node* newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    return;
}

void DoublyLinked::print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data;
        if (temp->next != NULL) std::cout << "->";
        temp = temp->next;
    }
    std::cout << std::endl;
    return;
}

void DoublyLinked::printReverse()
{
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        std::cout << temp->data;
        if (temp->prev != NULL) std::cout << "->";
        temp = temp->prev;
    }
    std::cout << std::endl;
    return;
}
