# C++ Learning Repository - Cheat Sheet

Welcome to the comprehensive C++ cheat sheet! Quick reference for all fundamental topics.

---

## Table of Contents

1. [Data Types & Variables](#data-types--variables)
2. [Control Flow](#control-flow)
3. [Functions](#functions)
4. [Arrays & Vectors](#arrays--vectors)
5. [Pointers & Memory](#pointers--memory)
6. [Classes & OOP](#classes--oop)

---

## Data Types & Variables

### Primitive Data Types

| Type | Size | Range | Example |
|------|------|-------|---------|
| `bool` | 1 byte | true/false | `bool flag = true;` |
| `char` | 1 byte | -128 to 127 | `char grade = 'A';` |
| `short` | 2 bytes | -32,768 to 32,767 | `short score = 100;` |
| `int` | 4 bytes | ~-2B to +2B | `int age = 25;` |
| `long` | 4-8 bytes | Large range | `long pop = 8000000000;` |
| `float` | 4 bytes | ~6-7 decimals | `float pi = 3.14f;` |
| `double` | 8 bytes | ~15-17 decimals | `double value = 3.14159;` |
| `string` | Variable | Any text | `string name = "Alice";` |

### Variable Declaration & Initialization

```cpp
int x;                          // Declaration only (not initialized)
int y = 10;                     // Declaration + Initialization
int a = 5, b = 10, c = 15;     // Multiple variables
float pi = 3.14f;              // Float literal with 'f'
string text = "Hello";         // String requires #include <string>
```

### Memory & Addresses

```cpp
int age = 25;
cout << age;                    // Value: 25
cout << &age;                   // Address: 0x232AC4
cout << sizeof(age);            // Size: 4 bytes
```

📖 **Full Tutorial**: See `Tutorials/01-DataTypes.txt`

---

## Control Flow

### Comparison Operators

```cpp
a == b      // Equal
a != b      // Not equal
a < b       // Less than
a > b       // Greater than
a <= b      // Less than or equal
a >= b      // Greater than or equal
```

### Logical Operators

```cpp
(a && b)    // AND: both true
(a || b)    // OR: at least one true
(!a)        // NOT: opposite
```

### If/Else Statements

```cpp
if (condition) {
    // Run if true
} else if (other_condition) {
    // Run if first false, this true
} else {
    // Run if all false
}
```

### Switch Statement

```cpp
switch (variable) {
    case value1:
        cout << "Case 1\n";
        break;
    case value2:
        cout << "Case 2\n";
        break;
    default:
        cout << "Default\n";
        break;
}
```

### Loops

**For Loop**
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";      // 0 1 2 3 4
}
```

**While Loop**
```cpp
int count = 0;
while (count < 5) {
    cout << count << " ";
    count++;
}
```

**Do-While Loop**
```cpp
int i = 0;
do {
    cout << i << " ";
    i++;
} while (i < 5);
```

**Break & Continue**
```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) break;      // Exit loop
    if (i == 2) continue;   // Skip iteration
    cout << i << " ";
}
```

📖 **Full Tutorial**: See `Tutorials/02-ControlFlow.txt`

---

## Functions

### Function Declaration & Definition

```cpp
// Declaration (Prototype)
int add(int a, int b);

// Definition
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);    // Call function
    cout << result;             // 8
}
```

### Parameters & Return Types

```cpp
// No parameters, returns int
int getAge() {
    return 25;
}

// Parameters, returns void
void greet(string name) {
    cout << "Hello, " << name << "!\n";
}

// Multiple parameters
float calculatePrice(float base, float tax, int qty) {
    return (base * qty) * (1 + tax);
}

// Default parameters
void printMessage(string msg = "Hello") {
    cout << msg << "\n";
}
```

### Function Overloading

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Call correct version based on arguments
add(5, 3);           // Calls int version
add(5.5, 3.2);       // Calls double version
```

### Scope

```cpp
int global = 100;    // Global scope

void func() {
    int local = 10;  // Local to func()
    global = 200;    // Can access global
}

int main() {
    cout << global;  // OK: 200
    cout << local;   // ERROR: local only exists in func()
}
```

📖 **Full Tutorial**: See `Tutorials/03-Functions.txt`

---

## Arrays & Vectors

### Arrays

```cpp
int scores[5];                               // Declare (not initialized)
int scores[5] = {85, 90, 78, 92, 88};      // Initialize with values
int scores[] = {85, 90, 78};                // Size from initializer

// Access elements (0-indexed)
cout << scores[0];      // 85 (first element)
scores[2] = 95;         // Modify element

// Loop through
for (int i = 0; i < 5; i++) {
    cout << scores[i] << " ";
}

// Get size
int size = sizeof(scores) / sizeof(scores[0]);
```

### Vectors (Preferred)

```cpp
#include <vector>
using std::vector;

vector<int> scores;                     // Empty vector
vector<int> scores = {85, 90, 78};      // Initialize with values
vector<int> scores(5);                  // Size 5, all zeros
vector<int> scores(5, 0);               // Size 5, all zeros

// Add elements
scores.push_back(92);       // Add to end
scores.pop_back();          // Remove from end

// Access
cout << scores[0];          // First element
cout << scores.size();      // Number of elements

// Loop
for (int i = 0; i < scores.size(); i++) {
    cout << scores[i] << " ";
}

// Range-based for (easier)
for (int score : scores) {
    cout << score << " ";
}
```

### Functions with Arrays/Vectors

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void printVector(vector<int> v) {
    for (int val : v) {
        cout << val << " ";
    }
}

// Call
int myArr[] = {1, 2, 3};
printArray(myArr, 3);

vector<int> myVec = {1, 2, 3};
printVector(myVec);
```

📖 **Full Tutorial**: See `Tutorials/04-Arrays.txt`

---

## Pointers & Memory

### Pointers Basics

```cpp
int age = 25;

&age                // Address-of: get address of age
int* ptr = &age;    // Declare pointer, store address
*ptr                // Dereference: get value at address

cout << age;        // 25 (value)
cout << &age;       // 0x232AC4 (address)
cout << *ptr;       // 25 (dereference pointer)
cout << ptr;        // 0x232AC4 (pointer value is address)
```

### Modifying Through Pointers

```cpp
int x = 10;
int* ptr = &x;

cout << x << "\n";      // 10
*ptr = 20;              // Change through pointer
cout << x << "\n";      // 20 (changed!)
```

### Pointers in Functions

```cpp
// Pass by value (original not changed)
void incrementByValue(int num) {
    num++;      // Changes copy
}

// Pass by pointer (original changed)
void incrementByPointer(int* numPtr) {
    (*numPtr)++;    // Changes original
}

int x = 5;
incrementByValue(x);        // x still 5
incrementByPointer(&x);     // x becomes 6
```

### Dynamic Memory Allocation

```cpp
// Allocate single variable
int* ptr = new int(25);      // Allocate and initialize
cout << *ptr;               // 25
delete ptr;                 // Free memory
ptr = nullptr;              // Set to null (good practice)

// Allocate array
int size = 5;
int* arr = new int[size];   // Allocate array

arr[0] = 10;                // Use like normal array

delete[] arr;               // delete[] for arrays!
arr = nullptr;
```

### nullptr

```cpp
int* ptr = nullptr;         // Safe: points to nothing

if (ptr != nullptr) {
    cout << *ptr << "\n";   // Safe: check first
}
```

📖 **Full Tutorial**: See `Tutorials/05-Pointers.txt`

---

## Classes & OOP

### Class Definition

```cpp
class Dog {
    public:
        string name;
        string breed;
        
        Dog() {                              // Constructor
            name = "Unknown";
        }
        
        Dog(string n, string b) {           // Parameterized constructor
            name = n;
            breed = b;
        }
        
        ~Dog() {                            // Destructor
            cout << "Dog destroyed\n";
        }
        
        void bark() {
            cout << name << " says: Woof!\n";
        }
};

// Create objects
Dog myDog;
Dog buddy("Buddy", "Golden Retriever");

// Use members
myDog.name = "Max";
myDog.bark();
```

### Access Modifiers

```cpp
class BankAccount {
    private:
        float balance;          // Only accessible inside class
    
    public:
        BankAccount(float initialBalance) {
            balance = initialBalance;
        }
        
        void deposit(float amount) {
            balance += amount;      // OK: inside class
        }
        
        float getBalance() {
            return balance;         // OK: inside class
        }
};

BankAccount acc(1000);
acc.deposit(100);               // OK: public function
cout << acc.getBalance();       // OK: public function
cout << acc.balance;            // ERROR: private
```

### Inheritance

```cpp
class Animal {                      // Base class
    public:
        string name;
        
        void eat() {
            cout << name << " is eating.\n";
        }
};

class Dog : public Animal {         // Derived class
    public:
        void bark() {
            cout << name << " says: Woof!\n";
        }
};

Dog myDog;
myDog.name = "Buddy";
myDog.eat();        // From Animal
myDog.bark();       // From Dog
```

### Function Overriding

```cpp
class Animal {
    public:
        void speak() {
            cout << "Generic sound\n";
        }
};

class Dog : public Animal {
    public:
        void speak() {              // Override
            cout << "Woof!\n";
        }
};

class Cat : public Animal {
    public:
        void speak() {              // Override
            cout << "Meow!\n";
        }
};
```

📖 **Full Tutorial**: See `Tutorials/06-OOP.txt`

---

## Quick Reference - Includes You'll Need

```cpp
#include <iostream>        // Input/output
#include <string>          // String class
#include <vector>          // Vector class
#include <cmath>           // Math functions (sqrt, sin, cos, etc.)
#include <ctime>           // Time/random
#include <iomanip>         // Output formatting
#include <fstream>         // File I/O

using std::cout;
using std::cin;
using std::string;
using std::vector;
```

---

## Common Patterns

### Input Validation Loop
```cpp
int age = -1;
while (age < 0) {
    cout << "Enter age: ";
    cin >> age;
    if (age < 0) {
        cout << "Must be positive!\n";
    }
}
```

### Find Maximum in Array
```cpp
int max = arr[0];
for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
```

### Sum Array Elements
```cpp
int sum = 0;
for (int val : arr) {
    sum += val;
}
```

### Check if Value Exists
```cpp
bool found = false;
for (int val : arr) {
    if (val == searchValue) {
        found = true;
        break;
    }
}
```

---

## Learning Path Recommendations

**Beginner:**
1. Start with `Tutorials/01-DataTypes.txt`
2. Then `Tutorials/02-ControlFlow.txt`
3. Move to `Tutorials/03-Functions.txt`

**Intermediate:**
4. Learn `Tutorials/04-Arrays.txt`
5. Study `Tutorials/05-Pointers.txt` (challenging but important)
6. Explore `Tutorials/06-OOP.txt`

**Practice:**
- Run the code examples from each tutorial
- Try the exercises suggested in each tutorial
- Look at examples in the `/C/` folder
- Study the `/Projects/Chess/` project for real OOP

---

## Tips for Success

✓ **Read each tutorial end-to-end** - They build on each other
✓ **Type code examples yourself** - Don't just copy/paste
✓ **Modify examples** - Change values, add features
✓ **Use the quick references** - This cheat sheet is for quick lookup
✓ **Review the Chess project** - See how real C++ code is structured
✓ **Compile and run frequently** - See what happens when code changes
✓ **Break when confused** - Take a break and come back fresh

Happy coding! 🚀
