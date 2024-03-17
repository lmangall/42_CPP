#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Search.hpp"
#include <limits> // For std::numeric_limits
#include <iomanip> // Include for setfill and setw



void displayOne(const Contact& contact)
{

	std::cout << std::endl << "  First Name_______" << contact.getFirstName() << std::endl;
	std::cout << "  Last Name________" << contact.getLastName() << std::endl;
	std::cout << "  Nickname_________" << contact.getNickname() << std::endl;
	std::cout << "  Phone Number_____" << contact.getPhoneNumber() << std::endl;
	std::cout << "  Darkest Secret___" << contact.getDarkestSecret() << std::endl << std::endl;

}

std::string truncateField(const std::string& field, std::string::size_type maxWidth)
{
   if (field.length() > maxWidth)
	   return field.substr(0, maxWidth - 1) + '.';
   else
   	   return field;
   
}


void displayAll(const PhoneBook& phoneBook) 
{
   int numContacts = 8;
   int maxFieldWidth = 10;

  std::cout << "\033[35m";

   std::cout << std::endl << std::endl;
   std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
             << "│     Index│First Name│ Last Name│  Nickname│\n"
             << "├──────────┼──────────┼──────────┼──────────┤\n";

	for (int index = 0; index < numContacts; ++index) {
       const Contact& contact = phoneBook.getContact(index);

       // Truncate all fields if necessary
       std::string firstName = truncateField(contact.getFirstName(), maxFieldWidth);
       std::string lastName = truncateField(contact.getLastName(), maxFieldWidth);
       std::string nickname = truncateField(contact.getNickname(), maxFieldWidth);

       std::cout << "│";
       std::cout << std::setfill(' ') << std::setw(maxFieldWidth) << index;
       std::cout << "│" << std::setw(maxFieldWidth) << firstName;
       std::cout << "│" << std::setw(maxFieldWidth) << lastName;
       std::cout << "│" << std::setw(maxFieldWidth) << nickname;
       std::cout << "│";
       std::cout << std::endl;

       std::cout << "├──────────┼──────────┼──────────┼──────────┤\n"; // Separator for each contact
   }

   std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
    std::cout << "\033[0m";
}



void searchContacts(PhoneBook& phoneBook)
{
	int index;
	bool valid = false;

	displayAll(phoneBook);

	while (!valid) {
		std::cout << std::endl << "Enter the index of the contact you want to search for or -1 to go back to the main menu:";
		std::cin >> index;
		int currentSize = phoneBook.getSize();

		if (index == -1) 
		{
        phoneBook.menu(phoneBook);
		}
		else if (std::cin.fail()) 
		{
			std::cin.clear(); // Clear the error state from the stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << std::endl << "Please enter a valid index: between 0 and " << currentSize - 1 << std::endl;
		} 
		else
		{
			if (index >= 0 && index < currentSize)
				valid = true;
			else
 				std::cout << std::endl << "\033[38;5;214mPlease enter a valid index: between 0 and " << currentSize - 1 << " \033[0m" << std::endl;		}
	}

	const Contact& contact = phoneBook.getContact(index);
	displayOne(contact);
}
