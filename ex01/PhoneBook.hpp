#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <cstddef> // For std::size_t

//The class declaration is in .hpp


class PhoneBook {
private:
    Contact contacts[8]; // Use a raw array to comply with C++98
    std::size_t currentSize; // Declaration without in-class initialization

public:
    PhoneBook(); // Constructor declaration
    void addContact(const Contact& newContact);
};

#endif // PHONEBOOK_HPP






// PhoneBook class has at least two public methods: addContact and searchContacts,