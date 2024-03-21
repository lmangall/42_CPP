#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) : _value(int_value << _fractionalBits) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : _value(roundf(float_value * (1 << _fractionalBits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _value = other._value;
        // std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// Comparison Operators
bool Fixed::operator>(const Fixed& rhs) const {
    return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_value != rhs._value;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs._value != 0) {
        return Fixed(this->toFloat() / rhs.toFloat());
    } else {
        std::cerr << "Error: Division by zero." << std::endl;
        return Fixed(0);
    }
}


Fixed& Fixed::operator++() {
    this->_value += (1 << _fractionalBits);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_value += (1 << _fractionalBits);
    return temp;
}

Fixed& Fixed::operator--() {
    this->_value -= (1 << _fractionalBits);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_value -= (1 << _fractionalBits);
    return temp;
}


// Static Member Functions for Min and Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {//ternary operator
    return (a < b) ? a : b;// condition ? result1 : result2;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Friend function for stream insertion
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
