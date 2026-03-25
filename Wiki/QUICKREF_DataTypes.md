# Quick Reference: Data Types & Variables

**For complete tutorial, see**: `Tutorials/01-DataTypes.txt`

## Primitive Data Types at a Glance

| Type | Size | Example | Use Case |
|------|------|---------|----------|
| `bool` | 1 | `true`, `false` | Yes/no flags |
| `char` | 1 | `'A'`, `'$'` | Single character |
| `short` | 2 | `-100` | Small integers |
| `int` | 4 | `25`, `2024` | General numbers |
| `long` | 8 | `8000000000` | Large integers |
| `float` | 4 | `3.14f` | Decimal (less precision) |
| `double` | 8 | `3.14159` | Decimal (more precision) |
| `string` | varies | `"Alice"` | Text (needs `#include <string>`) |

## Variable Declaration

```cpp
int age = 25;                    // Declare and initialize
float height = 5.9f;             // Float needs 'f' suffix
char grade = 'A';                // Single quotes for char
string name = "Alice";           // Double quotes for string
bool isValid = true;             // true or false
```

## Common Mistakes

```cpp
char letter = "A";               // WRONG: "A" is string, use 'A'
float value = 3.14;              // WRONG: default is double, use 3.14f
int x;                           // WRONG: uninitialized
cout << x;                       // DON'T: x has garbage value!
```

## Memory & Sizeof

```cpp
int age = 25;
cout << sizeof(age);             // Prints: 4 (bytes)
cout << sizeof(float);           // Prints: 4
cout << sizeof(double);          // Prints: 8
```

## Key Points

✓ Always initialize variables before using
✓ Use `double` by default for decimals, `float` only if necessary
✓ Use `string` for text (not `char[]`)
✓ Remember: `char` is single quote, `string` is double quote
