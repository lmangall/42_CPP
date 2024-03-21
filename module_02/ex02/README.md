Overloading:
Overloading the Insertion Operator (<<)
One common use of operator overloading is to define how objects of a custom class are output to streams, like the standard output stream (std::cout). By default, C++ does not know how to print custom types. Overloading the insertion (<<) operator allows you to specify exactly what gets printed when an object of your class is sent to an output stream.


Declaration and Definition
To overload the << operator for your class, you generally do the following:

Declare the operator function as a friend of your class (optional but common for <<): This isn't strictly necessary but is often done for the insertion operator because it allows the operator function to access private members of the class if necessary. It also changes the function signature slightly since the custom class object will be the second operand, not the first.

Define the operator function: This function should take two parameters: a reference to an std::ostream object (for the output stream) and a constant reference to your class object. It returns a reference to an std::ostream object to allow for chaining of output operations.

A friend function in C++ is a function that is not a member of a class but has access to the class's private and protected members.

```C

#include <iostream>

class Fixed {
public:
    // Example member function converting the object to float for output
    float toFloat() const { /* Implementation */ }

    // Overloading the << operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
        os << obj.toFloat(); // Use member function to get float representation
        return os; // Allow chaining
    }
};


```

________________________________










```C++
//static_cast<float>(_value) converts _value from an integer to a floating-point number. 
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}
```
```C++
// The conversion is done by shifting the integer value left by the number of fractional bits (_fractionalBits).
// For _fractionalBits = 8, this is equivalent to multiplying the integer by 256,
// effectively "scaling" the integer up to its fixed-point form where the last 8 bits represent the fractional part.
Fixed::Fixed(const int int_value) : _value(int_value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}
```

Fixed::Fixed(const float float_value) : _value(roundf(float_value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}
How `(float_value * (1 << _fractionalBits)` converts a float to a fixed-point value

### Fixed-Point Representation
We fix the number of bits that represent the fractional part to 8 : `_fractionalBits = 8`

For example, with 8 fractional bits:
- The value `1` in fixed-point representation is stored as `256` in integer (`1 << 8`), because the binary point is considered to be 8 bits from the right.
- Similarly, `0.5` is `128` (`0.5 * 256`), `0.25` is `64`, etc.

### Converting 
Fixed-Point = floating-point * 1 << _fractionalBits
floating-point= Fixed-Point / (1 <<_fractionalBits)
1 << 8 = 256

 1.75 Floating-Point to Fixed-Point 
Multiply 1.75 by 256 (1 << 8) = 448.
Fixed-Point Representation of value 448 in 16 bits binary is 00000001.11000000.

 2.25 Floating-Point to Fixed-Point 
Multiply 1.75 by 256 (1 << 8) = 576.
Fixed-Point Representation of value 448 in 16 bits binary is 00000010.01000000
​


### Detailed Example
Let's use a table to illustrate converting a fixed-point value to a floating-point number with `_fractionalBits = 8`.

| Fixed-Point(Integer) | Binary Representation | Operation   | Floating-Point Value |
|-----------------------|----------------------|-------------|----------------------|
| 256                   | `00000001.00000000`   | `256 / 256` | 1.0                 |
| 128                   | `00000000.10000000`   | `128 / 256` | 0.5                 |
| 64                    | `00000000.01000000`   | `64 / 256`  | 0.25                |
| 512                   | `00000010.00000000`   | `512 / 256` | 2.0                 |

In these examples, dividing the fixed-point `_value` by `2^_fractionalBits` (or `256` for `_fractionalBits = 8`) converts the integer representation back to the real number it represents. The division effectively moves the binary point back to its correct position to retrieve the original floating-point value.

This mechanism allows fixed-point arithmetic to perform operations with a level of precision determined by the number of fractional bits, using only integer math. When you need to display or further process these numbers as floating-point values, converting them back using the described method provides the actual floating-point equivalent.




