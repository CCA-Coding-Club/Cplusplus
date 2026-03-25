# Quick Reference: Functions

**For complete tutorial, see**: `Tutorials/03-Functions.txt`

## Function Syntax

```cpp
// Declaration (Prototype) - declares function exists
returnType functionName(parameters);

// Definition - the actual code
returnType functionName(parameters) {
    // Function body
    return value;  // if returnType is not void
}
```

## Simple Examples

```cpp
// No parameters, no return
void greet() {
    cout << "Hello!\n";
}

// Parameters, no return
void greet(string name) {
    cout << "Hello, " << name << "!\n";
}

// No parameters, returns value
int getAge() {
    return 25;
}

// Parameters and return value
int add(int a, int b) {
    return a + b;
}
```

## Calling Functions

```cpp
greet();                    // No parameters
greet("Alice");             // With parameters
int result = add(5, 3);     // Store return value
cout << add(5, 3);          // Use directly
```

## Multiple Parameters

```cpp
float calculatePrice(float basePrice, float taxRate, int quantity) {
    return (basePrice * quantity) * (1 + taxRate);
}

// Call with arguments in order
calculatePrice(10.0, 0.08, 5);
```

## Default Parameters

```cpp
void greet(string name = "Friend") {
    cout << "Hello, " << name << "!\n";
}

greet();           // Uses default: "Hello, Friend!"
greet("Alice");    // Uses provided: "Hello, Alice!"
```

## Function Overloading

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

add(5, 3);         // Calls int version
add(5.5, 3.2);     // Calls double version
```

## Scope

```cpp
int globalVar = 100;    // Global - accessible everywhere

void func() {
    int localVar = 10;  // Local - only in func()
    cout << globalVar;  // OK: access global
}

int main() {
    cout << globalVar;     // OK
    cout << localVar;      // ERROR: doesn't exist here
}
```

## Pass by Pointer (Modify Original)

```cpp
void increment(int* numPtr) {
    (*numPtr)++;       // Modify the original variable
}

int x = 5;
increment(&x);        // Pass address
// Now x is 6
```

## Typical Function Structure

```cpp
#include <iostream>
using std::cout;

// Declarations (Prototypes)
int multiply(int a, int b);
void printResult(int result);

int main() {
    int result = multiply(5, 3);
    printResult(result);
    return 0;
}

// Definitions
int multiply(int a, int b) {
    return a * b;
}

void printResult(int result) {
    cout << "Result: " << result << "\n";
}
```

## Key Points

✓ Declare function before using (prototype)
✓ Define function with actual code
✓ `void` = no return value
✓ Return immediately exits function
✓ Pass by pointer to modify originals
✓ Default parameters make functions flexible
✓ Overloading: same name, different parameters
