# Quick Reference: Classes & OOP

**For complete tutorial, see**: `Tutorials/06-OOP.txt`

## Class Definition

```cpp
class Dog {
    public:
        string name;
        string breed;
        
        Dog() {                              // Default constructor
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
```

## Creating Objects

```cpp
Dog myDog;                           // Uses default constructor
Dog buddy("Buddy", "Golden Ret");    // Uses parameterized constructor

// Access members
myDog.name = "Max";
myDog.bark();
```

## Member Functions (Methods)

```cpp
class Rectangle {
    public:
        float width;
        float height;
        
        float area() {
            return width * height;
        }
        
        float perimeter() {
            return 2 * (width + height);
        }
};

Rectangle rect;
rect.width = 5;
rect.height = 3;
cout << rect.area();        // 15
```

## Access Modifiers

```cpp
class BankAccount {
    private:                        // Only inside class
        float balance;
    
    public:                         // Inside and outside class
        BankAccount(float initial) {
            balance = initial;
        }
        
        void deposit(float amount) {
            balance += amount;      // Can access private here
        }
        
        float getBalance() {
            return balance;         // Can access private here
        }
};

BankAccount acc(1000);
acc.deposit(100);                   // OK
cout << acc.getBalance();           // OK
cout << acc.balance;                // ERROR: private!
```

## Constructors

```cpp
// Default constructor (no parameters)
class Person {
    public:
        Person() {
            name = "Unknown";
        }
};

// Parameterized constructor
class Person {
    public:
        Person(string n, int a) {
            name = n;
            age = a;
        }
};

// Both constructors
class Person {
    public:
        Person() { }                        // Default
        Person(string n, int a) { }         // Parameterized
};

Person p1;                  // Uses default
Person p2("Alice", 25);     // Uses parameterized
```

## Destructors

```cpp
class Person {
    public:
        Person() {
            cout << "Created\n";
        }
        
        ~Person() {             // Destructor
            cout << "Destroyed\n";
        }
};

Person p("Alice");          // Constructor runs
// ... use p ...
// ~Person() runs when p goes out of scope
```

## Inheritance

```cpp
class Animal {                      // Base class
    public:
        string name;
        
        void eat() {
            cout << name << " eats.\n";
        }
};

class Dog : public Animal {         // Derived class inherits from Animal
    public:
        void bark() {
            cout << name << " barks.\n";
        }
};

Dog myDog;
myDog.name = "Buddy";
myDog.eat();                // From Animal
myDog.bark();               // From Dog
```

## Function Overriding

```cpp
class Animal {
    public:
        void speak() {
            cout << "Generic sound.\n";
        }
};

class Dog : public Animal {
    public:
        void speak() {              // Override Animal's speak()
            cout << "Woof!\n";
        }
};

class Cat : public Animal {
    public:
        void speak() {              // Override Animal's speak()
            cout << "Meow!\n";
        }
};

Dog dog;
dog.speak();                // Prints: Woof!

Cat cat;
cat.speak();                // Prints: Meow!
```

## Complete Class Example

```cpp
class Student {
    private:
        string name;
        int studentID;
        float gpa;
    
    public:
        Student(string n, int id, float g) {
            name = n;
            studentID = id;
            gpa = g;
        }
        
        void printInfo() {
            cout << name << " (ID: " << studentID << ") GPA: " 
                 << gpa << "\n";
        }
        
        float getGPA() {
            return gpa;
        }
};

Student s1("Alice", 12345, 3.8);
s1.printInfo();             // Alice (ID: 12345) GPA: 3.8
cout << s1.getGPA();        // 3.8
```

## Public vs Private

| Access | Public | Private |
|--------|--------|---------|
| From outside class | ✓ | ✗ |
| From inside class | ✓ | ✓ |
| From derived class | ✓ | ✗ |

## Key Points

✓ Classes bundle data (member variables) and functions (methods)
✓ Constructors initialize objects automatically
✓ Destructors clean up when objects are destroyed
✓ Use `public` for interface, `private` for internal details
✓ Inheritance: derived class extends base class
✓ Override functions to customize behavior in derived classes
✓ Study the Chess project to see real OOP in action!
