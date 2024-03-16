#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Search.hpp"


void addExampleContacts(PhoneBook& phoneBook, bool populateWithExamples) {
  if (populateWithExamples) {
    const int numExamples = 6;  // Number of example contacts

    Contact exampleContacts[numExamples] = {
        // Contact("Devil", "Satan", "The Naughty One", "666-666-666", "can't eat spicy food"),
        Contact("The Dude", "Lebowski", "Duder, El Duderino, if you're not into the whole brevity thing", "", "Abides by his rug"),
        Contact("Thomas", "Anderson", "Neo, The One", "", "Followed a rabbit, took a pill, stayed in Wonderland"),
        Contact("Max", "Rockatansky", "Tom Hardy", "666-666-666", "Drove the Fury Road, chased by Immortan Joe"),
        Contact("Sarah", "Connor", "Linda Hamilton", "666-666-666", "Fought Terminators, raised John Connor"),
        Contact("Rick", "Deckard", "Blade Runner", "666-666-666", "Retired blade runner, hunted replicants"),
        Contact("Arthur", "Dent", "Ordinary Englishman", "666-666-666", "Travelled aboard the Heart of Gold, mostly harmless"),
        };

    for (int i = 0; i < numExamples; ++i) {
      phoneBook.addContact(exampleContacts[i]);
    }

    std::cout << "Phonebook populated with example contacts." << std::endl;
  }
}

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

    addExampleContacts(phoneBook, true);
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
        std::cout << " - SEARCH to search the phonebook" << std::endl;
        std::cout << " - EXIT to exit the program" << std::endl << std::endl;

        std::cin >> userChoice;

        if (userChoice == "ADD") {
            // Call addNewContact instead of phoneBook.addContact()
            addNewContact(phoneBook);
        } // Removed SEARCH case for brevity
        else if (userChoice == "SEARCH") {
            searchContacts(phoneBook);
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
