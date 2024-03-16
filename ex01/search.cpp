#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits> // For std::numeric_limits
#include <iomanip> // Include for setfill and setw


void displayOne(const Contact& contact)
{

	std::cout << " First Name_______" << contact.getFirstName() << std::endl;
	std::cout << " Last Name________" << contact.getLastName() << std::endl;
	std::cout << " Nickname_________" << contact.getNickname() << std::endl;
	std::cout << " Phone Number_____" << contact.getPhoneNumber() << std::endl;
	std::cout << " Darkest Secret___" << contact.getDarkestSecret() << std::endl << std::endl;

}

std::string truncateField(const std::string& field, std::size_t maxWidth) {
   if (field.length() > maxWidth) {
       return field.substr(0, maxWidth - 1) + '.';
   } else {
       return field;
   }
}


void displayAll(PhoneBook& phonebook) {
   (void)phonebook;

   std::size_t numContacts = phonebook.getSize();
   std::size_t maxFieldWidth = 10;  // Apply to all fields

   std::cout << "Phonebook" << std::endl;
   std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
             << "│     Index│First Name│ Last Name│  Nickname│\n"
             << "├──────────┼──────────┼──────────┼──────────┤\n";

   for (std::size_t index = 0; index < numContacts; ++index) {
       const Contact& contact = phonebook.getContact(index);

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
}



void searchContacts(PhoneBook& phonebook) {
size_t index;
bool valid = false;

displayAll(phonebook);

while (!valid) {
	std::cout << std::endl << "Enter the index of the contact you want to search for: ";
	std::cin >> index;

	if (std::cin.fail()) 
	{
	std::cin.clear(); // Clear the error state from the stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
	std::cout << std::endl << "Please enter an integer value: ";
	} 
	else
	{
	if (index >= 0 && index < phonebook.getSize())
		valid = true;
	else
		std::cout << std::endl << "Please enter a valid index: ";
	}
}

const Contact& contact = phonebook.getContact(index);
displayOne(contact);
}

