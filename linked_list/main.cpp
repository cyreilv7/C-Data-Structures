#include "linked_list.h"
#include <iostream>

// print linked list recursively
void printRecursive(Node* p, bool first_call=false)
{
    if (p == NULL) return;

    std::cout << p->data;

    if (p->next != NULL)
        std::cout << "->";

    printRecursive(p->next); // recursive call

    if (first_call)
        std::cout << std::endl;
        
    return;
}

void printReverse(Node* p, Node* head=NULL, bool first_call=false)
{
    if (p == NULL) return;

    printReverse(p->next); // recursive call

    std::cout << p->data;

    if (p != head)
        std::cout << "->";

    if (first_call)
        std::cout << std::endl;

    return;
}

void reverseListRecursive(Node** head, Node* p)
{
    if (p->next == NULL)
    {
        *head = p;
        return;
    }
    reverseListRecursive(head, p->next);
    Node* current = p->next;
    current->next = p;
    p->next = NULL;
    return;
}

int main()
{
    LinkedList list;

    list.insertNodeEnd(2);
    list.insertNodeEnd(4);
    list.insertNodeEnd(6);
    list.insertNodeEnd(5);
    list.print(); // expected: 2->4->6->5

    // list.deleteNodeEnd();
    // list.print(); // expected: 2->4->6

    list.deleteNodeNth(2);
    list.print(); // expected: 2->6->5
    // list.deleteNodeNth(4);
    // list.print(); // expected: 2->4->6

    // list.reverseList();
    // list.print(); // expected : 6->4->2

    // Node* head = list.getHead();

    // // note: head is a LOCAL variable, so it must be passed by reference
    // //       in order to change its value (i.e, WHAT it points to, not
    // //       the value at the stored address) in the function 
    // reverseListRecursive(&head, head); // expected: 2->4->6
    // printRecursive(head);

    // printRecursive(head, true); // expected: 2->4->6
    // printReverse(head, head, true); // expected: 6->4->2

    return 0;

}