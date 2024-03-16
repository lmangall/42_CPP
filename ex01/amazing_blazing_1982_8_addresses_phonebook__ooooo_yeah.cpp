#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

// Correct the function name to differentiate from PhoneBook's addContact
void addNewContact(PhoneBook& phoneBook) {
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    newContact.setFirstName(firstName);

    // Repeat for other fields...
    // After setting all properties, add the newContact to the phoneBook
    phoneBook.addContact(newContact);
}

void programStart(PhoneBook &phoneBook)
{
    std::string userChoice;

    while (true) 
    {
        std::cout << std::endl << "You have three options to choose from:" << std::endl;
        std::cout << " - ADD to save a new contact" << std::endl;
        std::cout << " - EXIT to exit the program" << std::endl << std::endl;

        std::cin >> userChoice;

        if (userChoice == "ADD") {
            // Call addNewContact instead of phoneBook.addContact()
            addNewContact(phoneBook);
        } // Removed SEARCH case for brevity
        else if (userChoice == "EXIT") {
            break;
        } else {
            std::cout << "Unrecognized option, please try again." << std::endl;
        }
    }
}

int main()
{
    PhoneBook phoneBook;
    programStart(phoneBook);
    return 0;
}



// Contact myContact("John", "Doe", "Johnny D", "123-456-7890", "Something unspeakable");
