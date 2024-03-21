#include "Fixed.hpp"


int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );

//Additionnal tests and prints for better understanding :

// Fixed const e( 1 );
// Fixed const f( 0.5f );
// Fixed const g( 1.25f );
// std::cout << std::endl;
// std::cout << "e is " << e << std::endl;
// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
// std::cout << "Binary representation of e: " << std::endl;
// e.printBinary();
// std::cout << std::endl;
// std::cout << "f is " << f << std::endl;
// std::cout << "f is " << f.toInt() << " as integer" << std::endl;
// std::cout << "Binary representation of f: " << std::endl;
// f.printBinary();
// std::cout << std::endl;
// std::cout << "g is " << g << std::endl;
// std::cout << "g is " << g.toInt() << " as integer" << std::endl;
// std::cout << "Binary representation of g: " << std::endl;
// g.printBinary();

std::cout << std::endl;
std::cout << "a is " << a << std::endl;//those 4 lines are using the overloaded operator <<
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << std::endl;

std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
