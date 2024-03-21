
```C++
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}
```

Function Body
return static_cast<float>(_value) / (1 << _fractionalBits);:
_value is presumably a private member variable of the Fixed class, storing the fixed-point number's value as an integer. The underscore prefix follows a naming convention indicating it's a private member.
_fractionalBits is likely another private member variable of the Fixed class, indicating the number of bits used to represent the fractional part of the fixed-point value.
static_cast<float>(_value) converts _value from an integer to a floating-point number. This is necessary because dividing two integers in C++ results in integer division, where the fractional part of the result is discarded. Casting _value to float ensures that floating-point division is used instead, preserving the fractional part of the division result.
(1 << _fractionalBits) performs a left bit shift on the number 1 by _fractionalBits places. Bit shifting 1 to the left n times is equivalent to calculating 2^n. This expression calculates the denominator for converting the fixed-point number to a floating-point number. For a fixed-point representation, this denominator represents the value of one unit in the least significant bit of the fractional part.
The division static_cast<float>(_value) / (1 << _fractionalBits) calculates the floating-point representation of the fixed-point number. The numerator is the fixed-point value cast to float, and the denominator is the value of one unit in the least significant bit of the fractional part, effectively converting the fixed-point value to its floating-point equivalent.
In summary, this function converts a fixed-point number, stored as an integer within the Fixed class, into its floating-point representation by dividing the integer value by 2^_fractionalBits, where _fractionalBits is the number of bits representing the fractional part of the number.
_______










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




