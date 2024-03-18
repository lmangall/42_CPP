
#include <iostream>
#include "Contact.hpp" // Includes the Contact class definition
#include "PhoneBook.hpp"

Contact::Contact() {}  // Default constructor

// Parameterized constructor
Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickname, std::string _phoneNumber, std::string _darkestSecret)
  : _firstName(_firstName), _lastName(_lastName), _nickname(_nickname), _phoneNumber(_phoneNumber), _darkestSecret(_darkestSecret) {}

// Setter functions
// this->_firstName = _firstName;: assigns the value of the argument _firstName to the _firstName member variable of the current object (this refers to the current object instance).
void Contact::set_firstName(const std::string &_firstName) { this->_firstName = _firstName; }
void Contact::set_lastName(const std::string &_lastName) { this->_lastName = _lastName; }
void Contact::set_nickname(const std::string &_nickname) { this->_nickname = _nickname; }
void Contact::set_phoneNumber(const std::string &_phoneNumber) { this->_phoneNumber = _phoneNumber; }
void Contact::set_darkestSecret(const std::string &_darkestSecret) { this->_darkestSecret = _darkestSecret; }

// Getter functions
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }


// Concepts explained in Contact.hpp

//In C++, this is a keyword that represents a pointer to the instance of the class in which it is used. 
//It is used to access the members of the class. this->_firstName refers to the _firstName member variable of the current object instance.
//it is use to avoid naming conflicts and to make the code more readable.