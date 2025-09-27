
// 1. Queue using Linked-List 

#include <iostream>
using namespace std;

// Node class for Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Queue class using Linked List
class Queue
{
private:
    Node *front; // points to front node
    Node *rear;  // points to rear node

public:
    // Constructor
    Queue()
    {
        front = rear = nullptr;
    }

    // Enqueue -> Insert element at rear
    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (rear == nullptr)
        { // Queue is empty
            front = rear = newNode;
            cout << val << " enqueued.\n";
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout << val << " enqueued.\n";
    }

    // Dequeue -> Remove element from front
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue Underflow! (Empty Queue)\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr) // If queue becomes empty
            rear = nullptr;

        cout << temp->data << " dequeued.\n";
        delete temp;
    }

    // Peek -> Get front element
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Display queue elements
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver code
int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << "\n";

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // underflow

    return 0;
}



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