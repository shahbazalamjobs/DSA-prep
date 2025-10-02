
## 🔹 What is `unordered_map`?

* It is an **associative container** in C++ STL.
* Stores data in **key–value pairs** (like a dictionary in Python).
* **Keys are unique** → no two same keys allowed.
* Implemented using **hash tables** → average **O(1)** lookup, insert, delete.

👉 Syntax:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Declaration
    unordered_map<int, string> myMap;

    // Insert elements
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Cherry";

    // Access elements
    cout << "Key 2 => " << myMap[2] << endl;

    return 0;
}
```

---

## 🔹 Common Operations

### 1. Insert Elements

```cpp
unordered_map<int, string> um;

// Method 1: Using operator[]
um[1] = "One";
um[2] = "Two";

// Method 2: Using insert()
um.insert({3, "Three"});
um.insert(make_pair(4, "Four"));
```

---

### 2. Access Elements

```cpp
cout << um[1] << endl;       // Output: One
cout << um.at(2) << endl;    // Output: Two
```

⚠️ Difference:

* `um[key]` → inserts default value if key not present.
* `um.at(key)` → throws exception if key not found.

---

### 3. Iterate Through Map

```cpp
for (auto &p : um) {
    cout << p.first << " -> " << p.second << endl;
}
```

`p.first` → key
`p.second` → value

---

### 4. Find and Check Key

```cpp
if (um.find(2) != um.end()) {
    cout << "Key 2 exists" << endl;
}

if (um.count(5) > 0) {
    cout << "Key 5 exists" << endl;
}
```

---

### 5. Erase Elements

```cpp
um.erase(2);            // erase key 2
um.erase(um.find(3));   // erase iterator
```

---

### 6. Size and Empty

```cpp
cout << "Size: " << um.size() << endl;
if (um.empty()) cout << "Map is empty";
```

---

## 🔹 Example Program (All Basics in One)

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;

    // Insert
    um[1] = "Apple";
    um[2] = "Banana";
    um.insert({3, "Cherry"});

    // Access
    cout << "Key 2: " << um.at(2) << endl;

    // Iterate
    cout << "All elements:\n";
    for (auto &p : um) {
        cout << p.first << " -> " << p.second << endl;
    }

    // Find
    if (um.find(3) != um.end()) {
        cout << "Found key 3\n";
    }

    // Erase
    um.erase(2);

    // Size
    cout << "Size after erase: " << um.size() << endl;

    return 0;
}
```

---

✅ **Key Points to Remember**

* Keys are unique.
* Order is **not maintained** (unlike `map`, which is sorted).
* Average O(1), worst O(n).
* Good when you need **fast lookup** without caring about order.

---

Do you want me to also give you a **comparison between `map` and `unordered_map`** (which is often asked in interviews)?
