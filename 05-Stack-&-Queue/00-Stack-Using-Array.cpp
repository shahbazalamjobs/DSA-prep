
// What is a Stack?

// Stack is a linear data structure that follows LIFO (Last In, First Out).
// Example: Plates stacked on each other. You put a new plate on top (push) and take from the top (pop).

// 📌 Basic Stack Operations
// push(x) → insert element at the top.
// pop() → remove element from the top.
// top() / peek() → get the top element without removing it.
// isEmpty() → check if stack is empty.
// isFull() (only if using fixed size array).

// 📌 Implementation Options
// Array-based Stack → Fixed size, simple.
// Linked List-based Stack → Dynamic size, flexible.

// 1. Stack usign Array using class
// Array-based stack → Simple, but fixed size (overflow possible).

#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "Top after pop: " << st.peek() << endl;

    return 0;
}

// 2. Using Struct

#include <iostream>
using namespace std;

// Stack structure using array
struct Stack
{
    int *arr;     // pointer to array
    int capacity; // maximum size of stack
    int top;      // index of top element

    // constructor
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // push operation
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack\n";
    }

    // pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    // peek operation
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // check if empty
    bool isEmpty()
    {
        return top == -1;
    }

    // check if full
    bool isFull()
    {
        return top == capacity - 1;
    }

    // destructor
    ~Stack()
    {
        delete[] arr;
    }
};

// Driver code
int main()
{
    Stack s(5); // stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "Top element is " << s.peek() << endl;

    if (s.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
