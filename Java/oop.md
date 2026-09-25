# Object-Oriented Programming (OOP) Notes

## 1. What is OOP?
Object-Oriented Programming is a programming style where code is organized around objects and classes.

- A class is a blueprint/template.
- An object is an instance of a class.
- OOP helps model real-world problems in a more organized and reusable way.

Example:

```java
class Animal {
    String name;

    void speak() {
        System.out.println("Animal makes a sound");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal dog = new Animal();
        dog.name = "Buddy";
        dog.speak();
    }
}
```

---

## 2. Core Principles of OOP

### a) Encapsulation
Encapsulation means hiding the internal details and exposing only what is needed.

- Use private fields.
- Provide public getter/setter methods.

Example:

```java
class Student {
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

Benefits:
- Protects data
- Improves maintainability
- Reduces accidental misuse

### b) Inheritance
Inheritance allows one class to inherit properties and methods from another class.

- Parent class = superclass
- Child class = subclass

Example:

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

Use case:
- Reuse code
- Create specialized classes from general ones

### c) Polymorphism
Polymorphism means one method or object can behave in different ways.

There are two main types:
- Compile-time polymorphism: method overloading
- Runtime polymorphism: method overriding

#### Method Overloading
Same method name, different parameters.

```java
class MathHelper {
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

#### Method Overriding
A subclass provides a different implementation of a method already defined in the parent class.

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

### d) Abstraction
Abstraction hides complex implementation details and shows only essential features.

- Abstract class
- Interface

Example:

```java
abstract class Vehicle {
    abstract void move();
}

class Car extends Vehicle {
    @Override
    void move() {
        System.out.println("Car is moving");
    }
}
```

Abstraction helps:
- Focus on what something does
- Simplify design
- Reduce complexity

---

## 3. Class and Object

### Class
A class is a blueprint that defines:
- fields (attributes)
- methods (behavior)
- constructors

### Object
An object is a real instance created from a class.

```java
class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Main {
    public static void main(String[] args) {
        Person p1 = new Person("Alice", 20);
        p1.display();
    }
}
```

---

## 4. Constructors
A constructor is a special method used to initialize objects.

- Same name as the class
- No return type
- Called automatically when an object is created

Example:

```java
class Book {
    String title;

    Book(String title) {
        this.title = title;
    }
}
```

Types:
- Default constructor
- Parameterized constructor

---

## 5. Access Modifiers
Access modifiers control visibility of classes, methods, and variables.

- public: accessible everywhere
- private: accessible only inside the class
- protected: accessible in same package and subclasses
- default: accessible within the same package

Example:

```java
class Example {
    private int x = 10;

    public int getX() {
        return x;
    }
}
```

---

## 6. Static Keyword
The static keyword is used for members shared by all objects of a class.

```java
class Counter {
    static int count = 0;

    Counter() {
        count++;
    }
}
```

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
