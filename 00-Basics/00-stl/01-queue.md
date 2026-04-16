Reversing a queue using a stack is a classic **LIFO + FIFO trick**:

* Queue → FIFO (First In First Out)
* Stack → LIFO (Last In First Out)

So if you push all queue elements into a stack, their order gets reversed. Then pushing them back into the queue gives a reversed queue.

---

### 💡 Logic (Step-by-step)

1. Take a queue `q`
2. Create an empty stack `s`
3. Pop each element from queue and push into stack
4. Now pop from stack and push back into queue

---

### ✅ C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // Step 1: Move elements from queue to stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Move elements back to queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

// Helper function to print queue
void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    printQueue(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}
```

---

### 🧠 Dry Run

Queue: `1 2 3 4`

**After pushing to stack:**
Stack (top → bottom): `4 3 2 1`

**After pushing back to queue:**
Queue: `4 3 2 1`

---

### ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (extra stack)

---

