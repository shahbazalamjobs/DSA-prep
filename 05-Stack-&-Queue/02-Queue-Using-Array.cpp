
// 1. Queue using Array

#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, capacity;

public:
    // Constructor
    Queue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }

    // Check if queue is full
    bool isFull()
    {
        return (rear == capacity - 1);
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    // Insert element
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0; // First insertion
        arr[++rear] = x;
        cout << x << " enqueued\n";
    }

    // Remove element
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
    }

    // Get front element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Display queue elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // This will show overflow

    q.display();

    return 0;
}
