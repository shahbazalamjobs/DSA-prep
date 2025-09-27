
// 1. Implement queue using 2 stacks

// TC: Enqueue: O(1)
// TC: Dequeue: O(1) (amortized)
// TC: Peek: O(1) (amortized)
// Sc: O(n)

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    // Enqueue operation
    void enqueue(int x)
    {
        s1.push(x);
    }

    // Dequeue operation
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    // Peek front element
    int front()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if queue is empty
    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;      // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    cout << "Front: " << q.front() << endl;      // 30

    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl; // 30
    cout << "Front: " << q.front() << endl;      // 40

    return 0;
}