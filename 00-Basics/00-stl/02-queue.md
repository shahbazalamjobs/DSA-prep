Here’s a clean, interview-focused + practical guide to **Queue in C++** (similar style to stack, but FIFO).

---

# 🔹 1. What is a Queue?

A **Queue** is a linear data structure that follows:

👉 **FIFO (First In First Out)**

* First element inserted → first one removed
* Like a real-life queue (line of people)

---

# 🔹 2. Queue in C++ (STL)

C++ provides queue in the **STL** using:

```cpp
#include <queue>
using namespace std;
```

---

# 🔹 3. Basic Syntax

```cpp
queue<int> q;
```

---

# 🔹 4. Common Operations (Most Important)

## ✅ 1. Push (Insert element)

```cpp
q.push(10);
q.push(20);
```

👉 Adds element at the **back**

---

## ✅ 2. Pop (Remove element)

```cpp
q.pop();
```

👉 Removes element from the **front**

⚠️ Does NOT return value

---

## ✅ 3. Front

```cpp
cout << q.front();
```

👉 Gives **first element**

---

## ✅ 4. Back

```cpp
cout << q.back();
```

👉 Gives **last element**

---

## ✅ 5. Empty

```cpp
if(q.empty()) {
    cout << "Queue is empty";
}
```

---

## ✅ 6. Size

```cpp
cout << q.size();
```

---

# 🔹 5. Example Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30

    q.pop(); // removes 10

    cout << "New Front: " << q.front() << endl; // 20

    return 0;
}
```

---

# 🔹 6. Common Input Patterns

## 🔸 1. Taking input into queue

```cpp
int n, x;
cin >> n;

queue<int> q;

for(int i = 0; i < n; i++) {
    cin >> x;
    q.push(x);
}
```

---

## 🔸 2. Input from array → queue

```cpp
int arr[] = {1, 2, 3, 4};

queue<int> q;

for(int i = 0; i < 4; i++) {
    q.push(arr[i]);
}
```

---

# 🔹 7. Common Output Patterns

## 🔸 1. Print and empty queue

```cpp
while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
```

---

## 🔸 2. Print without destroying (copy queue)

```cpp
queue<int> temp = q;

while(!temp.empty()) {
    cout << temp.front() << " ";
    temp.pop();
}
```

---

# 🔹 8. Important Variations (VERY COMMON)

## 🔸 1. Priority Queue (Max Heap)

```cpp
#include <queue>

priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top(); // 30 (largest)
```

---

## 🔸 2. Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## 🔸 3. Deque (Double Ended Queue)

```cpp
#include <deque>

deque<int> dq;

dq.push_front(10);
dq.push_back(20);

dq.pop_front();
dq.pop_back();
```

---

# 🔹 9. Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| push      | O(1)       |
| pop       | O(1)       |
| front     | O(1)       |
| back      | O(1)       |

---

# 🔹 10. Where Queues Are Used (Interview Gold)

* BFS (Graph traversal)
* Sliding window problems
* CPU scheduling
* Buffers (I/O)
* Level order traversal (trees)

---

# 🔹 11. Quick Revision (Pareto 20%)

If you only remember this, you're good:

```cpp
queue<int> q;

q.push(x);     // insert
q.pop();       // remove
q.front();     // first
q.back();      // last
q.empty();     // check
```

---

If you want next step 🚀
I can give you **top 5 queue problems (with patterns like BFS, sliding window, monotonic queue)** which are asked in interviews.
