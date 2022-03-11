#include "doubly_linked.h"

int main()
{
    DoublyLinked d;
    d.insertAtHead(0);
    d.insertAtHead(1);
    d.insertAtHead(2);
    d.insertAtTail(-1);
    d.print();
    d.printReverse();
    return 0;
}