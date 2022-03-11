// implementation of stack data structure using a static array
#include <iostream>
using namespace std;

class Stack
{
    private:
        static const int MAX_SIZE = 101;
        int arr[MAX_SIZE];
        int top;
    public:
        Stack() { top = -1; }
        ~Stack() {}
        void push(int);
        void pop();
        bool isEmpty();
        int peek(); // get top of stack
        void print();
};

// implementation of Stack methods
void Stack::push(int x)
{
    if (top == MAX_SIZE - 1)
        cout << "Error: exceeded max size of array";
    arr[++top] = x;
    return;
}

void Stack::pop()
{
    top--; 
}

bool Stack::isEmpty()
{
    return top == -1;
}

int Stack::peek()
{
    return arr[top];
}

void Stack::print()
{
    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

int main()
{
    Stack s;
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    cout << s.isEmpty() << endl;
    return 0;
}
