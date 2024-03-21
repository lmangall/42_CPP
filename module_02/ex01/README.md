The provided code snippets together define and implement a simple C++ project that demonstrates the usage of a class representing fixed-point numbers, designed according to the Orthodox Canonical Form (OCF). The project is composed of a class definition (`Fixed.h`), its implementation (`Fixed.cpp`), a main program for demonstration (`main.cpp`), and a `Makefile` for easy compilation. Here's a breakdown of each part's role:

### `Fixed.h` (Header File)
Defines the structure of the `Fixed` class, including:
- Private members:
  - `int value;`: An integer that stores the fixed-point number value.
  - `static const int fractionalBits;`: A static constant integer that defines the number of fractional bits, set to 8. This is used to differentiate between the integer and fractional parts of the fixed-point number, although its specific usage isn't shown in the provided snippets.
- Public members (functions):
  - A default constructor, copy constructor, copy assignment operator, and a destructor, following the OCF guidelines.
  - `int getRawBits(void) const;`: A member function that returns the raw integer value of the fixed-point number, allowing inspection of the object's state.
  - `void setRawBits(int const raw);`: Allows setting the raw integer value of the fixed-point number directly.

### `Fixed.cpp` (Implementation File)
Implements the `Fixed` class's functionality, specifically:
- **Default constructor**: Initializes the fixed-point number value to `0` and prints a message indicating it was called.
- **Copy constructor**: Initializes a new object as a copy of an existing object and prints a message. It directly copies the `value` from the other object.
- **Copy assignment operator**: Assigns one existing object's state to another, ensuring self-assignment is handled correctly (to prevent issues like memory leaks), and prints a message.
- **Destructor**: Cleans up resources (not explicitly needed here since there's no dynamic memory allocation) and prints a message upon object destruction.
- **`getRawBits`**: Returns the `value` of the fixed-point number and prints a message.
- **`setRawBits`**: Sets the `value` of the fixed-point number to a given raw integer.

### `main.cpp` (Main Program)
Demonstrates using the `Fixed` class by:
- Creating three `Fixed` objects (`a`, `b` as a copy of `a`, and `c`).
- Assigning the value of `b` to `c`.
- Printing the raw bits (the integer value) of `a`, `b`, and `c`, which demonstrates that all three have the same value (`0`, as set by the default constructor).

### `Makefile`
Provides a simple set of directives for compiling the project with `make`, including:
- Compiling the `main.cpp` and `Fixed.cpp` source files into object files (`main.o` and `Fixed.o`).
- Linking the object files into an executable named `a.out`.
- A `clean` command to remove the generated files.

### Output Explanation
When compiled and executed, the program:
- Indicates when each constructor, the copy assignment operator, and the destructor are called, helping visualize the object lifecycle in a C++ program.
- Demonstrates that the `getRawBits` function returns the value `0` for each object, as they were all either default-constructed or copy-constructed from an object with a `0` value.

This setup is a straightforward example of class design in C++, emphasizing the Orthodox Canonical Form and basic operations with fixed-point numbers.
