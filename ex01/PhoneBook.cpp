



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


std::string getValidInput(const std::string& prompt) {
    std::string input;

    do {
        if (!input.empty())
            std::cout << "\033[1;31mError: Input cannot be empty. Please try again.\033[0m" << std::endl;
        else
            std::cout << prompt;

        std::getline(std::cin, input);
    } while (input.empty());

    return input;
}


//& indicates that phoneBook is a reference to a PhoneBook object. 
void PhoneBook::createNewContact(PhoneBook& phoneBook)
{
    Contact newContact;

    newContact.set_firstName(getValidInput("Enter first name: "));
    newContact.set_lastName(getValidInput("Enter last name: "));
    newContact.set_nickname(getValidInput("Enter _nickname: "));
    // newContact.set_phoneNumber(getValidInput("Enter phone number: "));
    newContact.set_darkestSecret(getValidInput("Enter darkest secret: "));

    // std::cout << "Enter last name: ";
    // std::cin >> _lastName;
    // newContact.set_lastName(_lastName);

    // std::cout << "Enter _nickname: ";
    // std::cin >> _nickname;
    // newContact.set_nickname(_nickname);

    // std::cout << "Enter phone number: ";
    // std::cin >> _phoneNumber;
    // newContact.set_phoneNumber(_phoneNumber);

    // std::cout << "Enter darkest secret: ";
    // std::cin >> _darkestSecret;
    // newContact.set_darkestSecret(_darkestSecret);

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