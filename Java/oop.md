# Object-Oriented Programming (OOP) Notes

## 1. What is OOP?
Object-Oriented Programming (OOP) is a programming style where software is organized around objects and classes.

- A class is a blueprint or template.
- An object is an instance of a class.
- OOP models real-world entities like students, cars, animals, and accounts.

### Java example
```java
class Car {
    String brand;
    int speed;

    void drive() {
        System.out.println(brand + " is driving at " + speed + " km/h");
    }
}

public class Main {
    public static void main(String[] args) {
        Car c1 = new Car();
        c1.brand = "Toyota";
        c1.speed = 80;
        c1.drive();
    }
}
```

### Python example
```python
class Car:
    def __init__(self, brand, speed):
        self.brand = brand
        self.speed = speed

    def drive(self):
        print(f"{self.brand} is driving at {self.speed} km/h")

c1 = Car("Toyota", 80)
c1.drive()
```

### C++ example
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void drive() {
        cout << brand << " is driving at " << speed << " km/h" << endl;
    }
};

int main() {
    Car c1;
    c1.brand = "Toyota";
    c1.speed = 80;
    c1.drive();
    return 0;
}
```

### Rust example
```rust
struct Car {
    brand: String,
    speed: i32,
}

impl Car {
    fn drive(&self) {
        println!("{} is driving at {} km/h", self.brand, self.speed);
    }
}

fn main() {
    let c1 = Car {
        brand: String::from("Toyota"),
        speed: 80,
    };
    c1.drive();
}
```

---

## 2. Why use OOP?
OOP helps us write code that is:

- Reusable
- Organized
- Easy to maintain
- Easier to debug
- Better for large projects

A real-world example is a school system with classes like:
- Student
- Teacher
- Course
- Department

Each class handles its own data and behavior.

---

## 3. Core Principles of OOP
The four main pillars are:

1. Encapsulation
2. Inheritance
3. Polymorphism
4. Abstraction

---

## 4. Encapsulation
Encapsulation means wrapping data and methods together in a class and hiding internal details from outside code.

This protects data and allows controlled access.

### Java
```java
class BankAccount {
    private double balance;

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    public double getBalance() {
        return balance;
    }
}
```

### Python
```python
class BankAccount:
    def __init__(self):
        self.__balance = 0

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount

    def get_balance(self):
        return self.__balance
```

### C++
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};
```

### Rust
```rust
struct BankAccount {
    balance: f64,
}

impl BankAccount {
    fn new() -> Self {
        Self { balance: 0.0 }
    }

    fn deposit(&mut self, amount: f64) {
        if amount > 0.0 {
            self.balance += amount;
        }
    }

    fn get_balance(&self) -> f64 {
        self.balance
    }
}
```

### Why useful?
- Data is protected
- Invalid values can be blocked
- Code becomes more secure and maintainable

---

## 5. Inheritance
Inheritance lets one class reuse the features of another class.

- Parent class / base class
- Child class / derived class

### Java
```java
class Animal {
    void eat() {
        System.out.println("Eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Barking...");
    }
}
```

### Python
```python
class Animal:
    def eat(self):
        print("Eating...")

class Dog(Animal):
    def bark(self):
        print("Barking...")
```

### C++
```cpp
class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};
```

### Rust
Rust does not use traditional inheritance like Java or C++. Instead, it uses traits.

```rust
trait Animal {
    fn eat(&self);
}

struct Dog;

impl Animal for Dog {
    fn eat(&self) {
        println!("Eating...");
    }
}

impl Dog {
    fn bark(&self) {
        println!("Barking...");
    }
}
```

### Benefits
- Reuse code
- Build specialized classes
- Improve structure and organization

---

## 6. Polymorphism
Polymorphism means the same action can behave differently depending on the object.

### Java: method overloading
```java
class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

### Python: same method name, different behavior
```python
class Calculator:
    def add(self, a, b, c=None):
        if c is None:
            return a + b
        return a + b + c
```

### C++: function overloading
```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

### Rust: traits and generics
```rust
trait Addable {
    fn add(&self, other: &Self) -> Self;
}

impl Addable for i32 {
    fn add(&self, other: &Self) -> Self {
        self + other
    }
}
```

### Method overriding example in Java
```java
class Animal {
    void sound() {
        System.out.println("Some sound");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Meow");
    }
}
```

### Python overriding example
```python
class Animal:
    def sound(self):
        print("Some sound")

class Cat(Animal):
    def sound(self):
        print("Meow")
```

### C++ overriding example
```cpp
class Animal {
public:
    virtual void sound() {
        cout << "Some sound" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow" << endl;
    }
};
```

### Rust note
Rust uses traits and dynamic dispatch to achieve polymorphism without class inheritance.

---

## 7. Abstraction
Abstraction hides unnecessary details and exposes only the important behavior.

### Java abstract class
```java
abstract class Vehicle {
    abstract void move();
}

class Car extends Vehicle {
    void move() {
        System.out.println("Car is moving");
    }
}
```

### Python abstract base class
```python
from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def move(self):
        pass

class Car(Vehicle):
    def move(self):
        print("Car is moving")
```

### C++ abstract class
```cpp
class Vehicle {
public:
    virtual void move() = 0;
};

class Car : public Vehicle {
public:
    void move() override {
        cout << "Car is moving" << endl;
    }
};
```

### Rust trait abstraction
```rust
trait Vehicle {
    fn move_vehicle(&self);
}

struct Car;

impl Vehicle for Car {
    fn move_vehicle(&self) {
        println!("Car is moving");
    }
}
```

---

## 8. Class and Object

### Java
```java
class Person {
    String name;
    int age;

    void introduce() {
        System.out.println("Hi, I am " + name + ", age " + age);
    }
}
```

### Python
```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def introduce(self):
        print(f"Hi, I am {self.name}, age {self.age}")
```

### C++
```cpp
class Person {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I am " << name << ", age " << age << endl;
    }
};
```

### Rust
```rust
struct Person {
    name: String,
    age: i32,
}

impl Person {
    fn introduce(&self) {
        println!("Hi, I am {}, age {}", self.name, self.age);
    }
}
```

---

## 9. Constructors and Initialization
A constructor initializes an object when it is created.

### Java
```java
class Student {
    String name;

    Student(String name) {
        this.name = name;
    }
}
```

### Python
```python
class Student:
    def __init__(self, name):
        self.name = name
```

### C++
```cpp
class Student {
public:
    string name;

    Student(string n) : name(n) {}
};
```

### Rust
```rust
struct Student {
    name: String,
}

impl Student {
    fn new(name: &str) -> Self {
        Self {
            name: String::from(name),
        }
    }
}
```

---

## 10. Static Members / Class Members
Static members belong to the class, not to a single object.

### Java
```java
class Counter {
    static int count = 0;

    Counter() {
        count++;
    }
}
```

### Python
```python
class Counter:
    count = 0

    def __init__(self):
        Counter.count += 1
```

### C++
```cpp
class Counter {
public:
    static int count;

    Counter() {
        count++;
    }
};

int Counter::count = 0;
```

### Rust
Rust uses associated functions and static items instead of class-level static fields.

```rust
struct Counter;

impl Counter {
    fn new() -> Self {
        Self
    }
}
```

---

## 11. Access Modifiers and Visibility
Different languages control access differently.

### Java
- `public` = accessible everywhere
- `private` = only inside class
- `protected` = subclasses and same package

### Python
- `_x` = protected convention
- `__x` = name mangled private-like

### C++
- `public`, `private`, `protected`

### Rust
Rust uses strict visibility rules and modules.

```rust
mod account {
    pub struct BankAccount {
        balance: f64,
    }
}
```

---

## 12. Comparison Table

| Concept | Java | Python | C++ | Rust |
|---|---|---|---|---|
| Class | `class` | `class` | `class` | `struct` / `impl` |
| Object creation | `new` | constructor call | `Class obj;` | `Struct {}` |
| Inheritance | `extends` | class base | `:` | traits |
| Abstraction | abstract class/interface | ABC + abstractmethod | abstract class | trait |
| Polymorphism | overriding/overloading | overriding/default args | virtual functions/overloading | traits + generics |
| Encapsulation | access modifiers | naming conventions | access specifiers | module visibility |

---

## 13. Real-World Example: Student System

### Java
```java
class Student {
    private String name;
    private int marks;

    public Student(String name, int marks) {
        this.name = name;
        this.marks = marks;
    }

    public void showInfo() {
        System.out.println("Name: " + name + ", Marks: " + marks);
    }
}
```

### Python
```python
class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

    def show_info(self):
        print(f"Name: {self.name}, Marks: {self.marks}")
```

### C++
```cpp
class Student {
private:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    void showInfo() {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
};
```

### Rust
```rust
struct Student {
    name: String,
    marks: i32,
}

impl Student {
    fn new(name: &str, marks: i32) -> Self {
        Self {
            name: String::from(name),
            marks,
        }
    }

    fn show_info(&self) {
        println!("Name: {}, Marks: {}", self.name, self.marks);
    }
}
```

---

## 14. Important OOP Differences by Language

### Java
- Strongly object-oriented
- Built around classes and inheritance
- Best for enterprise and Android applications

### Python
- Object-oriented but flexible
- Easier syntax
- Often used in AI, web, scripting, and automation

### C++
- Powerful object-oriented and low-level features
- Supports both OOP and procedural styles
- Common in game engines, systems, and performance-critical apps

### Rust
- Uses OOP concepts but focuses on memory safety
- No classical inheritance
- Encourages composition and traits

---

## 15. Benefits of OOP in all languages
OOP helps in all four languages by promoting:

- Reusability
- Maintainability
- Clear organization
- Better modeling of real-world systems
- Easier team collaboration

---

## 16. Summary
All four languages support the main ideas of OOP, but they implement them differently:

- Java uses classes, inheritance, and interfaces
- Python uses classes and inheritance with simpler syntax
- C++ supports classical OOP with powerful features
- Rust uses structs, traits, and composition instead of traditional inheritance

The central idea remains the same:

- organize code into objects
- group related data and behavior
- hide complexity
- reuse logic

---

## 17. Quick Revision Questions
1. What is a class?
2. What is an object?
3. What is encapsulation?
4. What is inheritance?
5. What is polymorphism?
6. What is abstraction?
7. Which language is most similar to Java in OOP style?
8. How does Rust differ from Java and C++ in inheritance?
9. Which language is easiest for beginners to learn in OOP?
10. Why is OOP useful in large projects?

---

## 18. Final Thoughts
Object-Oriented Programming is one of the most important concepts in software engineering. Even though each language implements it differently, the core ideas are universal:

- model real-world objects
- keep data and behavior together
- hide complexity
- write reusable code

This makes OOP a foundation for building clean, scalable, and maintainable software.


Uses:
- static variables
- static methods
- static blocks

Static method example:

```java
class Demo {
    static void printMessage() {
        System.out.println("Hello from static method");
    }
}
```

Note:
- Static methods can be called without creating an object.
- They cannot directly access instance variables.

---

## 7. this Keyword
The this keyword refers to the current object.

```java
class Employee {
    String name;

    Employee(String name) {
        this.name = name;
    }
}
```

Use cases:
- differentiate fields from parameters
- call current object methods
- pass current object as argument

---

## 8. Packages and Modularity
A package is a way to group related classes.

```java
package mypackage;
```

Benefits:
- organize code
- avoid name conflicts
- improve maintainability

---

## 9. Interfaces vs Abstract Classes

### Abstract Class
- Can have abstract methods and normal methods
- Can have fields
- A class can extend only one abstract class

### Interface
- Contains abstract methods by default
- A class can implement many interfaces

Example:

```java
interface AnimalAction {
    void move();
}

class Bird implements AnimalAction {
    public void move() {
        System.out.println("Bird flies");
    }
}
```

---

## 10. Advantages of OOP
- Reusability
- Maintainability
- Easy debugging
- Better organization
- Real-world modeling
- Code scalability

---

## 11. Common OOP Interview Questions
- What is the difference between a class and an object?
- What is encapsulation?
- What is inheritance?
- What is polymorphism?
- What is abstraction?
- What is the difference between an abstract class and an interface?
- Why is OOP better than procedural programming?

---

## 12. Quick Summary
OOP is a programming model based on:
- Classes
- Objects
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

These concepts make software easier to design, manage, and extend.

---

## 13. Short Example Combining OOP Concepts

```java
class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    void sound() {
        System.out.println("Some sound");
    }
}

class Dog extends Animal {
    Dog(String name) {
        super(name);
    }

    @Override
    void sound() {
        System.out.println(name + " barks");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog("Buddy");
        a.sound();
    }
}
```

This example shows:
- inheritance
- method overriding
- polymorphism

---

## 14. Final Tip
When learning OOP, focus on understanding the relationship between classes and objects first. Then practice with small examples for inheritance, polymorphism, and encapsulation.

This will help you build strong fundamentals before moving to advanced Java concepts like collections, exception handling, and GUI programming.
