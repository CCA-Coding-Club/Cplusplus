# Quick Reference: Pointers & Memory

**For complete tutorial, see**: `Tutorials/05-Pointers.txt`

## Pointer Basics

```cpp
int age = 25;

&age                // Address-of: get memory address
int* agePtr;        // Declare: pointer to int
agePtr = &age;      // Initialize: store address
*agePtr             // Dereference: get value at address
agePtr              // The address itself
```

## Getting Addresses

```cpp
int x = 10;
cout << x;          // Value: 10
cout << &x;         // Address: 0x232AC4 (example)
```

## Creating Pointers

```cpp
int age = 25;
int* agePtr = &age;     // Declare and initialize

cout << agePtr;         // Address: 0x232AC4
cout << *agePtr;        // Value: 25
```

## Modifying Through Pointers

```cpp
int x = 10;
int* ptr = &x;

cout << x << "\n";      // 10
*ptr = 20;              // Change through pointer
cout << x << "\n";      // 20 (changed!)
```

## Important: Declare vs Dereference

```cpp
int* ptr = &x;          // Declaration: "ptr is pointer to int"
cout << *ptr;           // Dereference: "value at address in ptr"
```

## Pointers in Functions

```cpp
// Without pointer (copy)
void increment(int num) {
    num++;              // Changes copy only
}

// With pointer (original)
void increment(int* numPtr) {
    (*numPtr)++;        // Changes original
}

int x = 5;
increment(x);           // x still 5
increment(&x);          // x becomes 6
```

## Dynamic Memory Allocation

```cpp
// Allocate single variable
int* ptr = new int(25);     // Allocate and initialize
cout << *ptr;               // 25
delete ptr;                 // Free memory
ptr = nullptr;              // Set to null

// Allocate array
int* arr = new int[5];      // Allocate array of 5 ints
arr[0] = 10;
arr[1] = 20;
delete[] arr;               // Use delete[] for arrays!
arr = nullptr;
```

## nullptr - Safe Pointer State

```cpp
int* ptr = nullptr;         // Null pointer: points to nothing

if (ptr != nullptr) {
    cout << *ptr;           // Safe: check before use
}
```

## Dynamic Array Example

```cpp
int size;
cout << "Size: ";
cin >> size;

// Allocate based on user input
int* scores = new int[size];

// Use array
for (int i = 0; i < size; i++) {
    cin >> scores[i];
}

// Clean up
delete[] scores;
scores = nullptr;
```

## Pointer to Different Types

```cpp
float price = 9.99;
float* pricePtr = &price;

string name = "Alice";
string* namePtr = &name;

// Even pointers to pointers
int** ptrPtr = &ptr;
```

## Common Mistakes

```cpp
int* ptr;              // WRONG: uninitialized pointer
cout << *ptr;          // DANGER!

int x = 25;
int* ptr = x;          // WRONG: missing & (address-of)

delete ptr;            // WRONG: allocate array with new[], delete with delete[]
```

## Key Points

✓ `&` gets the address of a variable
✓ `*` dereferences a pointer (gets the value)
✓ Use pointers to change variables in functions
✓ `new` allocates memory, `delete` frees it
✓ Use `delete[]` for arrays allocated with `new[]`
✓ Always set pointer to `nullptr` after delete
✓ Check against `nullptr` before dereferencing
✓ Initialize pointers or set to `nullptr`
