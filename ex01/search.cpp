#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits> // For std::numeric_limits


void displayContacts(const PhoneBook& phonebook, int index, const Contact& contact)
{
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
  
}

void searchContacts(PhoneBook& phonebook) {
  int index;
  bool valid = false;

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
  displayContacts(phonebook, index, contact);
}

