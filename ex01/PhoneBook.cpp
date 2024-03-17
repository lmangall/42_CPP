



#include <array>
#include <cstddef> // For int
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Search.hpp"
#include <iostream>
#include <iomanip> // Include for setfill and setw

// Constructor definition
PhoneBook::PhoneBook() : currentSize(0) {} // Initialize currentSize in the constructor

void PhoneBook::menu(PhoneBook& phoneBook) {
  std::string userChoice;

  while (true) {
 std::cout << "\033[34m";

  // Display table header
  std::cout << std::endl << "   " << std::setw(18) << std::left << "MAIN MENU" << std::endl;

  // Display menu options with separators
  std::cout << "  --------------------------------------------" << std::endl;
  std::cout << "  - type " << std::setw(13) << std::left << "ADD" << " to save a new contact" << std::endl;
  std::cout << "  - type " << std::setw(13) << std::left << "SEARCH" << " to search the phonebook" << std::endl;
  std::cout << "  - type " << std::setw(13) << std::left << "EXIT" << " to exit the program" << std::endl;
  std::cout << "  --------------------------------------------" << std::endl;

  // Reset color to default
  std::cout << "\033[0m" << std::endl;

    std::cin >> userChoice;

    if (userChoice == "ADD") {
      phoneBook.createNewContact(phoneBook);
    }
    else if (userChoice == "SEARCH") {
      searchContacts(phoneBook);
    }
    else if (userChoice == "EXIT") {
        std::cout << "Goodbye!" << std::endl;
        exit(0);
    } else {
      std::cout << "Unrecognized option, please try again." << std::endl;
    }
  }
}

//& indicates that phoneBook is a reference to a PhoneBook object. 
void PhoneBook::createNewContact(PhoneBook& phoneBook)
{
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;


// A saved contact can’t have empty fields.
//number only numeric
//no pressing enter before input


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
        // contacts[currentSize] = newContact;
        // phoneBook.currentSize++;
        std::cout << "Contact added!" << std::endl;
    } else {
        std::cout << std::endl << "\033[38;5;214m  The phone book was full." << std::endl;
        std::cout << "  This last addition replaced the oldest contact" << std::endl << std::endl;
        std::cout << "\033[0m";
        // contacts[currentSize % 8] = newContact;
    }
    contacts[currentSize % 8] = newContact;
    phoneBook.currentSize++;
}

const Contact& PhoneBook::getContact(int index) const 
{return contacts[index];}

int PhoneBook::getSize() const
{return currentSize;}







// PhoneBook class has at least two public methods: addContact and searchContacts,