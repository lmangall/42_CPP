
#include <iostream>
#include "Contact.hpp" // Includes the Contact class definition
#include "PhoneBook.hpp" // NEEDED ?

Contact::Contact() {}  // Default constructor

// Parameterized constructor
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
  : firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

// Setter functions
// this->firstName = firstName;: assigns the value of the argument firstName to the firstName member variable of the current object (this refers to the current object instance).
void Contact::setFirstName(const std::string &firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string &lastName) { this->lastName = lastName; }
void Contact::setNickname(const std::string &nickname) { this->nickname = nickname; }
void Contact::setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

// Getter functions
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }


// Concepts explained in Contact.hpp

//In C++, this is a keyword that represents a pointer to the instance of the class in which it is used. 
//It is used to access the members of the class. this->firstName refers to the firstName member variable of the current object instance.
//it is use to avoid naming conflicts and to make the code more readable.