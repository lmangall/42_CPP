

Dependency Flags
DEPFLAGS = -MMD -MP
-MMD: Generates dependency files during compilation, excluding system headers. This helps in tracking dependencies for each source file to ensure that changes trigger recompilation of affected files only.
-MP: Adds a phony target for each dependency, mitigating errors when a dependency file is removed. It ensures the build process continues smoothly even if a non-critical header file is missing.




______________________

## We need to split our code with the four required member functions below:

Default Constructor
- Initializes a new instance of a class.
- Called when an object is created without providing explicit arguments.

Copy Constructor
- Initializes a new instance of a class by making a copy of an existing object.
- Called when an object is initialized from another object, passed as a copy to a function, or returned from a function by value.

Copy Assignment Operator
- Assigns the values from one instance of a class to another existing instance.
- Called when an object is assigned the value of another object of the same class.

Destructor
- Cleans up an instance of a class when it is no longer needed.
- Called automatically when an object goes out of scope or is explicitly deleted.

Using the OCF ensures that objects manage their resources (like dynamically allocated memory) correctly. It prevents resource leaks by ensuring that resources are properly freed when an object is destroyed, and it avoids undefined behavior by correctly handling the copying and moving of objects.





## Copy Constructor
Constructor that initializes a new object as a copy of an existing object. The syntax generally looks like ClassName(const ClassName& other), where other is the object to be copied.

```c++
class Box {
public:
    int width;
    Box(int w) : width(w) {} // Normal constructor
    Box(const Box& b) : width(b.width) {} // Copy constructor
};

int main() {
    Box box1(10);          // Normal constructor is called
    Box box2 = box1;       // Copy constructor is called

    return 0;
}
```
In this example, box1 is initialized using the normal constructor, and box2 is initialized as a copy of box1 using the copy constructor. The copy constructor is called when a new box object (box2) is created and initialized with the state of an existing box object (box1).




## Copy Assignment Operator
The copy assignment operator is used to copy the contents from one object to another existing object of the same class. It is often defined as ClassName& operator=(const ClassName& other).

```c++
class Box {
public:
    int width;
    Box(int w) : width(w) {} // Normal constructor
    Box(const Box& b) : width(b.width) {} // Copy constructor
    Box& operator=(const Box& b) { // Copy assignment operator
        width = b.width;
        return *this;
    }
};

int main() {
    Box box1(10); // Normal constructor is called
    Box box2(20); // Normal constructor is called
    box2 = box1;  // Copy assignment operator is called

    return 0;
}
```
In this scenario, both box1 and box2 are initially created with their respective widths. Later, the statement box2 = box1; invokes the copy assignment operator to copy the width of box1 into box2. After this operation, box2's width would be changed to 10, the same as box1's.