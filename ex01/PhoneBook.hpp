#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <cstddef> // For int

//The class declaration is in .hpp


class PhoneBook {
private:
    Contact contacts[8];
    int currentSize;
public:
    PhoneBook(); // Constructor declaration
//    ~PhoneBook();
    void createNewContact(PhoneBook& phoneBook); 
    void addContact(const Contact& newContact, PhoneBook& phoneBook);
    const Contact& getContact(int index) const;
    int getSize() const;
};

#endif






// PhoneBook class has at least two public methods: addContact and searchContacts,