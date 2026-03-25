# Quick Reference: Control Flow

**For complete tutorial, see**: `Tutorials/02-ControlFlow.txt`

## Comparison Operators

```cpp
a == b       // Equal
a != b       // Not equal
a < b        // Less than
a > b        // Greater than
a <= b       // Less than or equal to
a >= b       // Greater than or equal to
```

## Logical Operators

```cpp
(a && b)     // AND: both true
(a || b)     // OR: at least one true
(!a)         // NOT: opposite of a
```

## If/Else/Else If

```cpp
if (age >= 18) {
    cout << "Can vote.\n";
} else if (age >= 16) {
    cout << "Can drive.\n";
} else {
    cout << "Too young.\n";
}
```

## Switch Statement

```cpp
switch (choice) {
    case 1:
        cout << "Option 1\n";
        break;
    case 2:
        cout << "Option 2\n";
        break;
    default:
        cout << "Invalid\n";
        break;
}
```

**Important**: Always use `break;` in switch cases!

## Loops

### For Loop (know iterations)
```cpp
for (int i = 0; i < 5; i++) {    // i starts 0, goes while < 5, increments
    cout << i << " ";             // 0 1 2 3 4
}
```

### While Loop (unknown iterations)
```cpp
while (condition) {
    cout << "Running\n";
    // Change condition somewhere
}
```

### Do-While Loop (runs at least once)
```cpp
do {
    cout << "This runs at least once\n";
} while (condition);
```

## Loop Control

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) break;           // Exit loop completely
    if (i == 2) continue;        // Skip this iteration
    cout << i << " ";            // 0 1 3 4
}
```

## Common Patterns

### Input Validation
```cpp
int value = -1;
while (value < 0) {
    cout << "Enter positive: ";
    cin >> value;
}
```

### Count Down
```cpp
for (int i = 10; i >= 0; i--) {
    cout << i << " ";            // 10 9 8 ... 1 0
}
```

### Guess Game
```cpp
while (guess != answer) {
    cout << "Guess: ";
    cin >> guess;
    if (guess < answer) cout << "Too low\n";
    else if (guess > answer) cout << "Too high\n";
}
```

## Key Points

✓ Use `if/else` for complex conditions
✓ Use `switch` for one variable with many values
✓ Use `for` when you know loop count
✓ Use `while` when loop count depends on condition
✓ Don't forget `break;` in switch!
✓ Use `break` to exit loop early, `continue` to skip iteration
