



#include <array>
#include <cstddef> // For std::size_t
#include "Contact.hpp"


#include "PhoneBook.hpp"

// Constructor definition
PhoneBook::PhoneBook() : currentSize(0) {} // Initialize currentSize in the constructor

void PhoneBook::addContact(const Contact& newContact) {
    if (currentSize < 8) {
        contacts[currentSize] = newContact;
        currentSize++;
    } else {
        // Handle case where the phone book is full.
        // You might want to overwrite the oldest contact or similar.
    }
}







// PhoneBook class has at least two public methods: addContact and searchContacts,