Alright — let’s build this in a clean, interview-focused way (simple + practical).

---

# 📚 1. What is a Stack?

A **stack** is a data structure that follows:

👉 **LIFO (Last In, First Out)**
The last element you insert is the first one to come out.

### Real-life example:

* Stack of plates 🍽️
  You remove the top plate first.

---

# ⚙️ 2. Stack in C++

C++ provides a built-in stack using:

```cpp
#include <stack>
using namespace std;

stack<int> st;
```

---

# 🔑 3. Basic Operations (MOST IMPORTANT)

These are the only ones you need for 90% of problems:

| Operation | Meaning                 |
| --------- | ----------------------- |
| `push(x)` | Insert element          |
| `pop()`   | Remove top element      |
| `top()`   | Get top element         |
| `empty()` | Check if stack is empty |
| `size()`  | Number of elements      |

---

# 🧪 4. Example Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30

    st.pop(); // removes 30

    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Size: " << st.size() << endl;

    if (st.empty()) {
        cout << "Stack is empty";
    } else {
        cout << "Stack is not empty";
    }

    return 0;
}
```

---

# 🔄 5. Common Input Pattern

### Case 1: Input n elements and push into stack

```cpp
int n;
cin >> n;

stack<int> st;

for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
}
```

---

# 📤 6. Common Output Pattern

### Print and remove all elements

```cpp
while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
}
```

⚠️ Output will be **reverse order** of input (because of LIFO)

---

# 🧠 7. Important Interview Patterns

These come again and again:

### 1. Reverse array/string using stack

### 2. Balanced parentheses `() {} []`

### 3. Next Greater Element

### 4. Stock Span Problem

### 5. Monotonic Stack problems

---

# ⚡ 8. Time Complexity

| Operation | Time |
| --------- | ---- |
| push      | O(1) |
| pop       | O(1) |
| top       | O(1) |

---

# 🚀 9. Pro Tip (Important)

👉 Stack is just a wrapper over **deque (by default)**
👉 You can also implement it using:

* Array
* Vector
* Linked List

---

# 🧩 10. Quick Practice Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
```

---

If you want next step, I can:
👉 Explain **monotonic stack (VERY IMPORTANT for interviews)**
👉 Or solve **Next Greater Element / Stock Span step-by-step**
