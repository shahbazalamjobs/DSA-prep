
# 🔹 What is OOP?

OOP (Object-Oriented Programming) is a way of writing programs using **classes and objects** to organize code and model real-world entities.

---

# 🔹 1. Class and Object

### 📌 Class

A class is a **blueprint** for creating objects.

### 📌 Object

An object is an **instance of a class**.

### ✅ Example:

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void show() {
        cout << brand << " " << speed << endl;
    }
};

int main() {
    Car c1;              // object
    c1.brand = "BMW";
    c1.speed = 200;

    c1.show();           // BMW 200
}
```

---

# 🔹 2. Encapsulation

### 📌 Meaning:

Wrapping data (variables) and methods (functions) together in a class.

👉 Use **private** variables + **public** methods to control access.

### ✅ Example:

```cpp
class Bank {
private:
    int balance;

public:
    void setBalance(int b) {
        balance = b;
    }

    int getBalance() {
        return balance;
    }
};
```

---

# 🔹 3. Abstraction

### 📌 Meaning:

Showing only **important details** and hiding internal implementation.

👉 Achieved using **classes & access specifiers**

### ✅ Example:

```cpp
class ATM {
public:
    void withdraw() {
        cout << "Processing...\n";  // internal logic hidden
    }
};
```

---

# 🔹 4. Inheritance

### 📌 Meaning:

One class **inherits** properties of another class.

👉 Promotes code reuse

### ✅ Syntax:

```cpp
class Parent {
public:
    void show() {
        cout << "Parent class\n";
    }
};

class Child : public Parent {
public:
    void display() {
        cout << "Child class\n";
    }
};
```

### ✅ Usage:

```cpp
Child c;
c.show();     // inherited
c.display();
```

---

# 🔹 5. Polymorphism

### 📌 Meaning:

**One name, multiple forms**

---

## 🔸 (A) Compile-time Polymorphism (Function Overloading)

```cpp
class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

---

## 🔸 (B) Runtime Polymorphism (Function Overriding)

```cpp
class Animal {
public:
    void sound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Dog barks\n";
    }
};
```

---

# 🔹 6. Constructor

### 📌 Meaning:

Special function that is **automatically called** when object is created.

### ✅ Example:

```cpp
class Student {
public:
    string name;

    Student(string n) {   // constructor
        name = n;
    }
};
```

---

# 🔹 7. Destructor

### 📌 Meaning:

Called when object is destroyed.

```cpp
class Test {
public:
    ~Test() {
        cout << "Object destroyed\n";
    }
};
```

---

# 🔹 8. Access Specifiers

| Specifier | Meaning                             |
| --------- | ----------------------------------- |
| public    | Accessible everywhere               |
| private   | Accessible only inside class        |
| protected | Accessible in class + derived class |

---

# 🔹 OOP Pillars (Must Remember for Interviews)

1. **Encapsulation**
2. **Abstraction**
3. **Inheritance**
4. **Polymorphism**

---

# 🔥 Quick Interview Summary (80/20)

- Class = blueprint
- Object = instance
- Encapsulation = data hiding
- Inheritance = reuse code
- Polymorphism = same function, different behavior
- Constructor = initializes object

---
