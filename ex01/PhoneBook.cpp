



#include <array>
#include <cstddef> // For std::size_t
#include "Contact.hpp"
#include <iostream>


#include "PhoneBook.hpp"

// Constructor definition
PhoneBook::PhoneBook() : currentSize(0) {} // Initialize currentSize in the constructor

void PhoneBook::addContact(const Contact& newContact) {
    if (currentSize < 8) {
        contacts[currentSize] = newContact;
        currentSize++;
    } else {
        std::cout << "The phone book is full." << std::endl;
        std::cout << "This last addition replaced the oldest contact" << std::endl;
        contacts[currentSize] = newContact;        
    }
}







// PhoneBook class has at least two public methods: addContact and searchContacts,