#include <iostream>
#include <string>




int main(void){
	std::string brain_str = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain_str;// • stringPTR: A pointer to the string.
	std::string &stringREF = brain_str;// • stringREF: A reference to the string.

	std::cout << std::endl << "We are printing..." << std::endl << std::endl;

	std::cout << "The memory address of the string variable:   " << &brain_str << std::endl;
	std::cout << "The memory address held by stringPTR:        " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:        " << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable:            " << brain_str << std::endl;
	std::cout << "The value pointed to by stringPTR:           " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringPTR:           " << stringREF << std::endl;

	return 0;
}