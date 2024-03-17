#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Search.hpp"
#include <iomanip> // Include for setfill and setw


void fillPhonebook(PhoneBook& phoneBook)
{
    const int numExamples = 8;

    Contact exampleContacts[numExamples] = {
        // Contact("Devil", "Satan", "The Naughty One", "666-666-666", "can't eat spicy food"),
        Contact("The Dude", "Lebowski", "Duder, El Duderino, if you're not into the whole brevity thing", "6666666666", "Abides by his rug"),
        Contact("Thomas", "Anderson", "Neo, The One", "6666666666", "Followed a rabbit, took a pill, stayed in Wonderland"),
        Contact("Max", "Rockatansky", "Tom Hardy", "6666666666", "Drove the Fury Road, chased by Immortan Joe"),
        Contact("Sarah", "Connor", "Linda Hamilton", "6666666666", "Fought Terminators, raised John Connor"),
        Contact("Rick", "Deckard", "Blade Runner", "6666666666", "Retired blade runner, hunted replicants"),
        Contact("Zaphod", "Beeblebrox", "Two-headed, semi-retired Galactic President", "6666666666", "Has two heads, mostly harmless (except for the other head)"),
        Contact("Marvin", "the Paranoid Android", "The most depressed robot in the Universe", "6666666666", "Secretly yearns to be happy but believes happiness is impossible"),
        Contact("Mini", "Shell", "MiniHell, the mighty, fuc*** hell", "6666666666", "Makes your life hell (not a secret)"), 
        };

    for (int i = 0; i < numExamples; ++i) {
            phoneBook.addContact(exampleContacts[i], phoneBook);
    }

    std::cout << "\033[31mPhonebook populated with example contacts for ease of use.\033[0m" << std::endl;
}

void programStart()
{

    std::string userChoice;

        std::cout << "\033[32m";
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
        std::cout << "\033[0m";

}

int main()
{
    PhoneBook phoneBook;
    fillPhonebook(phoneBook);//                         uncomment to test the code pre-filled
    programStart();//direct call to function
    phoneBook.menu(phoneBook);//call to function using object
    return 0;
}

