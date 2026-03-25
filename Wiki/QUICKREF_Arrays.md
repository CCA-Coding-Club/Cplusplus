# Quick Reference: Arrays & Vectors

**For complete tutorial, see**: `Tutorials/04-Arrays.txt`

## Arrays - Fixed Size

```cpp
int scores[5];                               // Declare (not initialized)
int scores[5] = {85, 90, 78, 92, 88};      // With values
int scores[] = {85, 90, 78};                // Size auto-detected

// Access (0-indexed)
cout << scores[0];      // 85
scores[2] = 95;         // Modify

// Loop through
for (int i = 0; i < 5; i++) {
    cout << scores[i];
}
```

## Vectors - Dynamic Size (Preferred!)

```cpp
#include <vector>
using std::vector;

vector<int> scores;                    // Empty
vector<int> scores = {85, 90, 78};     // With values
vector<int> scores(5);                 // Size 5, all zeros
vector<int> scores(5, 0);              // Size 5, all zeros

// Add/Remove
scores.push_back(92);      // Add to end
scores.pop_back();         // Remove last

// Access
cout << scores[0];         // First element
cout << scores.size();     // Number of elements

// Loop
for (int i = 0; i < scores.size(); i++) {
    cout << scores[i];
}

// Range-based for (easier!)
for (int score : scores) {
    cout << score;
}
```

## Arrays in Functions

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int myArr[] = {1, 2, 3};
printArray(myArr, 3);
```

## Vectors in Functions

```cpp
void printVector(vector<int> v) {
    for (int val : v) {
        cout << val << " ";
    }
}

vector<int> myVec = {1, 2, 3};
printVector(myVec);
```

## Common Operations

### Find Sum
```cpp
int sum = 0;
for (int val : scores) {
    sum += val;
}
```

### Find Maximum
```cpp
int max = scores[0];
for (int i = 1; i < scores.size(); i++) {
    if (scores[i] > max) max = scores[i];
}
```

### Find Minimum
```cpp
int min = scores[0];
for (int val : scores) {
    if (val < min) min = val;
}
```

### Search for Value
```cpp
int searchVal = 90;
bool found = false;
for (int val : scores) {
    if (val == searchVal) {
        found = true;
        break;
    }
}
```

### Calculate Average
```cpp
int sum = 0;
for (int val : scores) {
    sum += val;
}
double avg = (double)sum / scores.size();
```

## Array vs Vector

| Feature | Array | Vector |
|---------|-------|--------|
| Size | Fixed | Dynamic |
| Add elements | No | `push_back()` |
| Size function | Manual | `size()` |
| Memory | Stack | Heap |
| When to use | Fixed size | Most cases |

## Key Points

✓ Arrays are 0-indexed (first is [0])
✓ Vectors are usually better than arrays
✓ Use `size()` with vectors, track manually for arrays
✓ `push_back()` adds to vector
✓ `pop_back()` removes from vector
✓ Range-based `for` is easiest way to loop
✓ Pass vectors by reference if you want to modify them
