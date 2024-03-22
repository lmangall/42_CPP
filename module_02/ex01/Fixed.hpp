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
    Fixed(const int int_value);
    Fixed(const float float_value);//using the f suffix
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;           // Converts to floating-point _value
    int toInt(void) const;               // Converts to integer _value

    void printBinary() const; // Addition to better understand

};
    std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
