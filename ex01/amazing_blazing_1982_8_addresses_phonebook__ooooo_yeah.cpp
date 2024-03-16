#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

//& indicates that phoneBook is a reference to a PhoneBook object. 
void addNewContact(PhoneBook& phoneBook) 
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

    std::cout << std::endl << "contact added, going back to main menu:" << std::endl;

    phoneBook.addContact(newContact);
}

void programStart(PhoneBook &phoneBook)
{
    std::string userChoice;

        std::cout << "     _________" << std::endl;
        std::cout << "    / ======= \\" << std::endl;
        std::cout << "   / __________\\" << std::endl;
        std::cout << "  | ___________ |" << std::endl;
        std::cout << "  | | -       | |" << std::endl;
        std::cout << "  | |         | |" << std::endl;
        std::cout << "  | |_________| |________________________________" << std::endl;
        std::cout << "  \\=____________/   Welcome to the phonebook    )" << std::endl;
        std::cout << "  / \"\"\"\"\"\"\"\"\"\"\" \\                             /" << std::endl;
        std::cout << " / ::::::::::::: \\                         =D-'" << std::endl;
        std::cout << "(_________________)" << std::endl << std::endl;

    while (true) 
    {

        std::cout << "You have three options to choose from:" << std::endl;
        std::cout << " - ADD to save a new contact" << std::endl;
        std::cout << " - EXIT to exit the program" << std::endl << std::endl;

        std::cin >> userChoice;

        if (userChoice == "ADD") {
            // Call addNewContact instead of phoneBook.addContact()
            addNewContact(phoneBook);
        } // Removed SEARCH case for brevity
        else if (userChoice == "SEARCH") {
            std::cout << "Search function not implemented yet." << std::endl;

        }
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
