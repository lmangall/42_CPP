#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int int_value);          // Constructs a fixed-point number from an integer
    Fixed(const float float_value);      // Constructs a fixed-point number from a floating-point number
    Fixed(const Fixed& other);          // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;           // Converts to floating-point _value
    int toInt(void) const;               // Converts to integer _value

    // Overloads << to output the _value of a Fixed object as a float
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif // FIXED_H
