// Fixed.h - Header file for the Fixed class
#ifndef FIXED_H
#define FIXED_H

class Fixed {
private:
    int _value; // Stores the fixed-point number value
    static const int _fractionalBits = 8; // Number of fractional bits, always 8

public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const; // Returns the raw value of the fixed-point number
    void setRawBits(int const raw); // Sets the raw value of the fixed-point number
};

#endif // FIXED_H
