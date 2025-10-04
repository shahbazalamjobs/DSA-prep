
**C++ vectors**

---

## **1. What is a vector?**

A **vector** is a dynamic array in C++. Unlike regular arrays:

* Its **size can grow or shrink** at runtime.
* Provides **many built-in functions** for easy management.
* Stored in **contiguous memory**, so you can access elements using `[]` or iterators.

Think of a vector like an **array that can expand itself automatically**.

---

## **2. Include vector**

```cpp
#include <vector>
```

And typically, we use:

```cpp
using namespace std;
```

---

## **3. How to declare a vector**

```cpp
vector<int> v1;          // empty vector of integers
vector<int> v2(5);       // vector of size 5 (default values 0)
vector<int> v3(5, 10);   // vector of size 5, all initialized to 10
vector<int> v4 = {1,2,3,4}; // vector with initial values
```

* **`v2(5)`** → `[0,0,0,0,0]`
* **`v3(5,10)`** → `[10,10,10,10,10]`

---

## **4. Access elements**

```cpp
v1.push_back(5);     // add 5 at the end
v1.push_back(10);    // add 10 at the end

cout << v1[0];       // 5 (index starts at 0)
cout << v1.at(1);    // 10 (safer, throws exception if out of bounds)
```

---

## **5. Size and capacity**

```cpp
cout << v1.size();     // number of elements
cout << v1.capacity(); // how much memory is reserved
```

* **`size()`** → actual elements
* **`capacity()`** → total allocated space (can be larger than size)

---

## **6. Remove elements**

```cpp
v1.pop_back();  // removes last element
v1.clear();     // removes all elements
```

---

## **7. Iterating a vector**

### **a. Using index**

```cpp
for(int i=0; i<v1.size(); i++)
    cout << v1[i] << " ";
```

### **b. Using range-based loop**

```cpp
for(int x : v1)
    cout << x << " ";
```

### **c. Using iterators**

```cpp
for(auto it = v1.begin(); it != v1.end(); ++it)
    cout << *it << " ";
```

---

## **8. Inserting and erasing**

```cpp
v1.insert(v1.begin(), 100); // insert 100 at beginning
v1.erase(v1.begin());       // erase first element
```

---

## **9. Common vector functions**

| Function           | Description                       |
| ------------------ | --------------------------------- |
| `push_back(val)`   | Add element at the end            |
| `pop_back()`       | Remove last element               |
| `size()`           | Returns number of elements        |
| `capacity()`       | Returns memory allocated          |
| `empty()`          | Checks if vector is empty         |
| `clear()`          | Removes all elements              |
| `front()`          | Returns first element             |
| `back()`           | Returns last element              |
| `insert(pos, val)` | Insert at position                |
| `erase(pos)`       | Remove element at position        |
| `begin(), end()`   | Iterators for traversal           |
| `resize(n)`        | Resize vector to n elements       |
| `swap(v2)`         | Swap contents with another vector |

---

## **10. Example program**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1,2,3};
    
    v.push_back(4);   // add 4
    cout << "Vector: ";
    for(int x : v) cout << x << " "; // 1 2 3 4
    cout << endl;

    v.pop_back();     // remove last
    cout << "After pop_back: ";
    for(int x : v) cout << x << " "; // 1 2 3
    cout << endl;

    v.insert(v.begin() + 1, 10); // insert 10 at index 1
    cout << "After insert: ";
    for(int x : v) cout << x << " "; // 1 10 2 3
    cout << endl;

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

    return 0;
}
```

---

## **11. Time Complexity**

| Operation           | Complexity     |
| ------------------- | -------------- |
| Access element `[]` | O(1)           |
| `push_back`         | O(1) amortized |
| `pop_back`          | O(1)           |
| Insert/Erase middle | O(n)           |
| Iterating           | O(n)           |

---

✅ **Summary:** Vectors are dynamic arrays, easier to use than raw arrays, with powerful functions for insertion, deletion, and traversal.

---

