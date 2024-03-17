



#include <array>
#include <cstddef> // For int
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Search.hpp"
#include <iostream>


#include "PhoneBook.hpp"

// Constructor definition
PhoneBook::PhoneBook() : currentSize(0) {} // Initialize currentSize in the constructor


//& indicates that phoneBook is a reference to a PhoneBook object. 
void PhoneBook::createNewContact(PhoneBook& phoneBook)
{
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    newContact.setFirstName(firstName);

    std::cout << "Enter last name: ";
    std::cin >> lastName;
    newContact.setLastName(lastName);

    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    newContact.setNickname(nickname);

    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    newContact.setPhoneNumber(phoneNumber);

    std::cout << "Enter darkest secret: ";
    std::cin >> darkestSecret;
    newContact.setDarkestSecret(darkestSecret);

    //std::cout << std::endl << "contact added, going back to main menu:" << std::endl;

    phoneBook.addContact(newContact, phoneBook);
}

void PhoneBook::addContact(const Contact& newContact, PhoneBook& phoneBook) 
{
    int currentSize = phoneBook.getSize();
    if (currentSize < 8) {
        contacts[currentSize++] = newContact;
        phoneBook.currentSize++;
    } else {
        std::cout  << std::endl << "  The phone book was full." << std::endl;
        std::cout << "  This last addition replaced the oldest contact" << std::endl << std::endl;
        contacts[currentSize] = newContact;        
    }
}

const Contact& PhoneBook::getContact(int index) const 
{return contacts[index];}

int PhoneBook::getSize() const
{return currentSize;}





// PhoneBook class has at least two public methods: addContact and searchContacts,