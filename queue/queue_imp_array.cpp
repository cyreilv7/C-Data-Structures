// implementation of queue ADT with a 'circular' array

#include <iostream>
using namespace std;

class Queue
{
    public:
        static const int size = 6;
        int arr[size];
        int front,
            rear;
        Queue();
        ~Queue() {}
        bool isEmpty();
        bool isFull();
        void enqueue(int);
        void dequeue();
        int getFront();

};

Queue::Queue()
{
    // array empty state
    front = -1;
    rear = -1;
}

bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

bool Queue::isFull()
{
    return (rear + 1) % size == front;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is already full!" << endl;
        return;
    }

    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % size;

    arr[rear] = x;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is already empty!" << endl;
        return;
    }
    // if only 1 spot left, reset queue to empty state
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % size;

    return;
}

int Queue::getFront()
{
    if (front != -1)
        return arr[front];
    return 0;
}

int main()
{
    Queue q;
    q.isEmpty() ? cout << "true" << endl : cout << "false" << endl;;
    q.dequeue(); // expected: warning output
    for (int i = 0; !q.isFull(); i++)
    {
        q.enqueue(i);
        cout << q.arr[i] << endl;
    }

    while (!q.isEmpty())
    {
        cout << "front: " << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}