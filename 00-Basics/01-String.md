Sure — here are all the **same C++ string basics examples**, but now with **input/output shown in comments**, so it's easier to understand.

---

# 🔹 1. Declaration & Initialization

```cpp id="zq5f38"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2("World");
    string s3;

    cout << s1 << " " << s2 << endl;
}

// Output:
// Hello World
```

---

# 🔹 2. Taking Input

### ➤ Using `cin`

```cpp id="2n7h3e"
string s;
cin >> s;
cout << s;

// Input:
// Hello

// Output:
// Hello
```

⚠ `cin` stops at space.

---

### ➤ Using `getline()`

```cpp id="cp0slo"
string s;
getline(cin, s);
cout << s;

// Input:
// Hello World

// Output:
// Hello World
```

---

# 🔹 3. Length / Size

```cpp id="8czkh5"
string s = "Hello";

cout << s.length() << endl;
cout << s.size();

// Output:
// 5
// 5
```

---

# 🔹 4. Access Characters

```cpp id="r6v6zf"
string s = "Hello";

cout << s[0] << endl;
cout << s.at(1);

// Output:
// H
// e
```

---

# 🔹 5. Concatenation

```cpp id="xjygt5"
string a = "Hello";
string b = "World";

string c = a + b;
cout << c << endl;

a += " C++";
cout << a;

// Output:
// HelloWorld
// Hello C++
```

---

# 🔹 6. Comparison

```cpp id="m0f0o9"
string a = "apple";
string b = "banana";

cout << (a == b) << endl;
cout << (a < b);

// Output:
// 0
// 1
```

---

# 🔹 7. Loop Through String

### ➤ Index loop

```cpp id="n17lh2"
string s = "Hi";

for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}

// Output:
// H i
```

---

### ➤ Range-based loop

```cpp id="f3bxvb"
string s = "Hi";

for (char c : s) {
    cout << c << " ";
}

// Output:
// H i
```

---

# 🔹 8. Substring

```cpp id="zyu6xa"
string s = "Hello";

cout << s.substr(1, 3);

// Output:
// ell
```

---

# 🔹 9. Find

```cpp id="lbwujn"
string s = "Hello";

cout << s.find("lo");

// Output:
// 3
```

If not found:

```cpp id="h7nqth"
cout << s.find("xy");

// Output:
// 18446744073709551615
```

That means **`string::npos`**

Better:

```cpp id="65b0j5"
if (s.find("xy") == string::npos)
    cout << "Not found";

// Output:
// Not found
```

---

# 🔹 10. Append

```cpp id="jzckmq"
string s = "Hi";

s.append(" There");
cout << s;

// Output:
// Hi There
```

---

# 🔹 11. Insert

```cpp id="ogd8hh"
string s = "Helo";

s.insert(2, "l");
cout << s;

// Output:
// Hello
```

---

# 🔹 12. Erase

```cpp id="t0pv4q"
string s = "Hello";

s.erase(1, 2);
cout << s;

// Output:
// Hlo
```

---

# 🔹 13. Reverse

```cpp id="11m1oe"
#include <algorithm>

string s = "Hello";

reverse(s.begin(), s.end());
cout << s;

// Output:
// olleH
```

---

# 🔹 14. Modify Character

```cpp id="8w5akz"
string s = "hello";

s[0] = 'H';
cout << s;

// Output:
// Hello
```

---

# 🔹 15. Full Example

```cpp id="eu9xuy"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello";

    s[0] = 'H';
    s += " world";

    cout << s << endl;
}

// Output:
// Hello world
```

---

If you'd like next, I can give you **important string functions cheat sheet for interviews** like:

```cpp
find(), substr(), erase(), stoi(), to_string(), reverse()
```

with examples + outputs in comments — very useful for DSA interviews.
