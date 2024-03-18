#include <cstddef> // For int
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Search.hpp"
#include <iostream>
#include <iomanip> // Include for setfill and setw
#include <cstdlib>  // For std::exit

// Constructor definition
PhoneBook::PhoneBook() : currentSize(0) {} // Initialize currentSize in the constructor

void PhoneBook::menu(PhoneBook& phoneBook) {
  std::string userChoice;

  while (true)
  {

    //setw => Sets the minimum field for next print - be right-padded with spaces if less than the specified width.
    std::cout << "\033[34m";
    std::cout << std::endl << "   " << std::setw(18) << std::left << "MAIN MENU" << std::endl;
    std::cout << "  --------------------------------------------" << std::endl;
    std::cout << "  - type " << std::setw(13) << std::left << "ADD" << " to save a new contact" << std::endl;
    std::cout << "  - type " << std::setw(13) << std::left << "SEARCH" << " to search the phonebook" << std::endl;
    std::cout << "  - type " << std::setw(13) << std::left << "EXIT" << " to exit the program" << std::endl;
    std::cout << "  --------------------------------------------" << std::endl;
    std::cout << "\033[0m" << std::endl;

        std::cin >> userChoice;

        if (userChoice == "ADD")
        phoneBook.createNewContact(phoneBook);
        else if (userChoice == "SEARCH")
        searchContacts(phoneBook);
        else if (userChoice == "EXIT") {
            std::exit(0);
        } else
        std::cout << "\033[1;31mUnrecognized option, please try again.\033[0m" << std::endl;
  }
}


std::string getValidInput(const std::string& prompt)
{
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


//& indicates that phoneBook is a reference to a PhoneBook object.  (similar pointer)
void PhoneBook::createNewContact(PhoneBook& phoneBook)
{
    Contact newContact;

    newContact.set_firstName(getValidInput("Enter first name: "));
    newContact.set_lastName(getValidInput("Enter last name: "));
    newContact.set_nickname(getValidInput("Enter nickname: "));
    newContact.set_darkestSecret(getValidInput("Enter darkest secret: "));

    std::string phoneNumber;
    bool allDigits;
    do {
        phoneNumber = getValidInput("Enter phone number (digits only): ");

        allDigits = true;
        if (phoneNumber.length() != 10) {
            allDigits = false;
        } else {
            for (int i = 0; i < 10; ++i) {
                char c = phoneNumber[i];
                if (!std::isdigit(c)) {
                    allDigits = false;
                    break;
                }
            }
        }
        newContact.set_phoneNumber(phoneNumber);

        if (!allDigits) {
            std::cout << "\033[1;31mError: Phone number must contain only 10 digits. Please try again.\033[0m" << std::endl;
        }
    } while (!allDigits);

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