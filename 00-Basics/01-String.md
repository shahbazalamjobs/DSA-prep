# String
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

Got it — here’s a **🔥 interview-focused string cheat sheet in C++** with **examples + input/output in comments**.

---

# 🚀 Must-Know String Functions (C++)

Using std::string

---

# 🔹 1. `find()`

Finds first occurrence of substring.

```cpp
string s = "hello world";

cout << s.find("world");

// Output:
// 6
```

```cpp
cout << s.find("xyz");

// Output:
// 18446744073709551615  (means string::npos)
```

---

# 🔹 2. `substr()`

Extract substring.

```cpp
string s = "hello";

cout << s.substr(1, 3);

// Output:
// ell
```

---

# 🔹 3. `erase()`

Remove characters.

```cpp
string s = "hello";

s.erase(1, 2);
cout << s;

// Output:
// hlo
```

---

# 🔹 4. `insert()`

Insert at position.

```cpp
string s = "heo";

s.insert(2, "l");
cout << s;

// Output:
// helo
```

---

# 🔹 5. `append()`

Add at end.

```cpp
string s = "hello";

s.append(" world");
cout << s;

// Output:
// hello world
```

---

# 🔹 6. `reverse()`

From `<algorithm>`

```cpp
#include <algorithm>

string s = "abc";

reverse(s.begin(), s.end());
cout << s;

// Output:
// cba
```

---

# 🔹 7. `stoi()` (String → Integer)

```cpp
string s = "123";

int x = stoi(s);
cout << x + 10;

// Output:
// 133
```

---

# 🔹 8. `to_string()` (Integer → String)

```cpp
int x = 456;

string s = to_string(x);
cout << s + "7";

// Output:
// 4567
```

---

# 🔹 9. `sort()`

```cpp
#include <algorithm>

string s = "dcba";

sort(s.begin(), s.end());
cout << s;

// Output:
// abcd
```

---

# 🔹 10. `compare()`

```cpp
string a = "abc";
string b = "abc";

cout << a.compare(b);

// Output:
// 0   (means equal)
```

---

# 🔹 11. `push_back()` and `pop_back()`

```cpp
string s = "abc";

s.push_back('d');
cout << s << endl;

s.pop_back();
cout << s;

// Output:
// abcd
// abc
```

---

# 🔹 12. `empty()`

```cpp
string s = "";

cout << s.empty();

// Output:
// 1  (true)
```

---

# 🔹 13. `clear()`

```cpp
string s = "hello";

s.clear();
cout << s;

// Output:
// (empty string)
```

---

# 🔹 14. `front()` and `back()`

```cpp
string s = "hello";

cout << s.front() << endl;
cout << s.back();

// Output:
// h
// o
```

---

# 🔥 Most Important Interview Combos

### ✔ Reverse string

```cpp
reverse(s.begin(), s.end());
```

---

### ✔ Check palindrome

```cpp
string s = "madam";
string t = s;

reverse(t.begin(), t.end());

cout << (s == t);

// Output:
// 1 (true)
```

---

### ✔ Anagram check (sorting)

```cpp
string a = "listen";
string b = "silent";

sort(a.begin(), a.end());
sort(b.begin(), b.end());

cout << (a == b);

// Output:
// 1
```

---

### ✔ Count frequency

```cpp
string s = "aab";

int freq[26] = {0};

for(char c : s) {
    freq[c - 'a']++;
}

cout << freq[0];

// Output:
// 2  (count of 'a')
```

---

# ⚡ Pro Tips (Very Important)

* `find()` → always check against `string::npos`
* `substr(start, length)` → NOT ending index
* `reverse`, `sort` → need `<algorithm>`
* Strings are **mutable** (can change characters)

---




