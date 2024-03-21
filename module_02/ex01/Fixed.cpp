#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// The conversion is done by shifting the integer value left by the number of fractional bits (_fractionalBits).
// For _fractionalBits = 8, this is equivalent to multiplying the integer by 256,
// effectively "scaling" the integer up to its fixed-point form where the last 8 bits represent the fractional part.
Fixed::Fixed(const int int_value) : _value(int_value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : _value(roundf(float_value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _value = other._value;
        std::cout << "Copy assignment operator called (this is also a form of operator overloading, specifically overloading the copy assignment operator (=))" << std::endl;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

//static_cast<float>(_value) converts _value from an integer to a floating-point number. 
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

//C++ operator overloading declaration and definition for the insertion (<<) 
//this operator overload allows objects of the Fixed class to be directly output to any output stream using the << operator,
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}


void Fixed::printBinary() const {
    std::bitset<16> binary(_value);
    std::string binaryStr = binary.to_string();


    binaryStr.insert(binaryStr.length() - _fractionalBits, ".");

    std::cout << "Binary: " << binaryStr << std::endl;
}