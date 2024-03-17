#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Search.hpp"
#include <iomanip> // Include for setfill and setw


void fillPhonebook(PhoneBook& phoneBook, bool populateWithExamples) {
  if (populateWithExamples) {
    const int numExamples = 8;

    Contact exampleContacts[numExamples] = {
        // Contact("Devil", "Satan", "The Naughty One", "666-666-666", "can't eat spicy food"),
        Contact("The Dude", "Lebowski", "Duder, El Duderino, if you're not into the whole brevity thing", "", "Abides by his rug"),
        Contact("Thomas", "Anderson", "Neo, The One", "", "Followed a rabbit, took a pill, stayed in Wonderland"),
        Contact("Max", "Rockatansky", "Tom Hardy", "666-666-666", "Drove the Fury Road, chased by Immortan Joe"),
        Contact("Sarah", "Connor", "Linda Hamilton", "666-666-666", "Fought Terminators, raised John Connor"),
        Contact("Rick", "Deckard", "Blade Runner", "666-666-666", "Retired blade runner, hunted replicants"),
        Contact("Zaphod", "Beeblebrox", "Two-headed, semi-retired Galactic President", "666-666-666", "Has two heads, mostly harmless (except for the other head)"),
        Contact("Marvin", "the Paranoid Android", "The most depressed robot in the Universe", "Error: Does not compute", "Secretly yearns to be happy but believes happiness is impossible"),
        Contact("Mini", "Shell", "MiniHell, the mighty, fuc*** hell", "666-666-666", "Makes your life hell (not a secret)"), 
        };

    for (int i = 0; i < numExamples; ++i) {
            phoneBook.addContact(exampleContacts[i], phoneBook);
    }

    std::cout << "\033[31mPhonebook populated with example contacts for ease of use.\033[0m" << std::endl;
  }
}

void menu(PhoneBook& phoneBook) {
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
      break;
    } else {
      std::cout << "Unrecognized option, please try again." << std::endl;
    }
  }
}

void programStart(PhoneBook &phoneBook)
{

    fillPhonebook(phoneBook, true);
    std::string userChoice;

        std::cout << "\033[32m"; // Set text color to green (code 32)
        std::cout << "     _________" << std::endl;
        std::cout << "    / ======= \\" << std::endl;
        std::cout << "   / __________\\" << std::endl;
        std::cout << "  | ___________ |" << std::endl;
        std::cout << "  | | -       | |" << std::endl;
        std::cout << "  | |         | |" << std::endl;
        std::cout << "  | |_________| |________________________________" << std::endl;
        std::cout << "  \\=____________/   Welcome to the phonebook     )" << std::endl;
        std::cout << "  / \"\"\"\"\"\"\"\"\"\"\" \\                               /" << std::endl;
        std::cout << " / ::::::::::::: \\                          =D-'" << std::endl;
        std::cout << "(_________________)" << std::endl << std::endl;
        std::cout << "\033[0m"; // Reset text color to default

}

int main()
{
    PhoneBook phoneBook;
    programStart(phoneBook);
    menu(phoneBook);
    return 0;
}



// Contact myContact("John", "Doe", "Johnny D", "123-456-7890", "Something unspeakable");
