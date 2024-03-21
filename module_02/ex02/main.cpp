#include "Fixed.hpp"

//main from the subject
// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

//main with more tests:
#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << c << std::endl;
	std::cout << "e: " << c << std::endl;
	
    // Testing arithmetic operators
    std::cout << "Arithmetic Operators:" << std::endl;
    e = b + c;
    std::cout << b << " + " << c << " = " << e << std::endl;

    e = c - b;
    std::cout << c << " - " << b << " = " << e << std::endl;

    e = b * Fixed(2);
    std::cout << b << " * " << Fixed(2) << " = " << e << std::endl;

    e = c / Fixed(2.0f);
    std::cout << c << " / " << Fixed(2.0f) << " = " << e << std::endl;

    // Testing comparison operators
    std::cout << "\nComparison Operators:" << std::endl;
    std::cout << b << " > " << c << " = " << (b > c) << std::endl;
    std::cout << b << " < " << c << " = " << (b < c) << std::endl;
    std::cout << b << " == " << d << " = " << (b == d) << std::endl;
    std::cout << b << " != " << c << " = " << (b != c) << std::endl;

    // Testing increment/decrement operators
    std::cout << "\nIncrement/Decrement Operators:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;

    // Testing static min/max functions
    std::cout << "\nStatic min/max Functions:" << std::endl;
    std::cout << "Min of " << b << " and " << c << " = " << Fixed::min(b, c) << std::endl;
    std::cout << "Max of " << b << " and " << c << " = " << Fixed::max(b, c) << std::endl;

    return 0;
}
