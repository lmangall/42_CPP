

Project Structure
Project Root Directory (e.g., ex01/):
Makefile: Contains instructions for compiling your project.
main.cpp: The entry point of your program. It should handle user inputs and outputs.
PhoneBook.hpp: Header file for the PhoneBook class.
PhoneBook.cpp: Implementation file for the PhoneBook class.
Contact.hpp: Header file for the Contact class.
Contact.cpp: Implementation file for the Contact class.

Naming Conventions
Files:

Use .cpp for C++ source files and .hpp or .h for header files.
File names should be descriptive and reflect the purpose or the class they are implementing, e.g., PhoneBook.cpp for the PhoneBook class implementation.
Classes:

Class names should be nouns and start with a capital letter. Use CamelCase for multi-word names, e.g., PhoneBook, Contact.
Functions:

Use verbs to name functions since functions perform actions.
Use camelCase starting with a lowercase letter, e.g., addContact(), searchContact().
Variables:

Use meaningful names that describe the purpose of the variable.
Use camelCase starting with a lowercase letter, e.g., phoneNumber, darkestSecret.
Makefile
Your Makefile should at least have rules for all (or default rule), clean, fclean, re.
Use variables for compiler (CXX), compiler flags (CXXFLAGS), and your source files (SRC).
The all rule builds the executable, clean removes object files, fclean removes both object files and the executable, and re makes fclean followed by all.
Basic Flow in main.cpp
Main Loop: Prompt the user for commands (ADD, SEARCH, EXIT) in a loop.
Command Handling:
ADD: Invoke a method of PhoneBook to add a new Contact.
SEARCH: Display a list of contacts and prompt for an index to display detailed contact info.
EXIT: Break the loop and end the program.
Additional Tips
Encapsulation: Keep data members of Contact and PhoneBook private. Provide public member functions to manipulate these data.
Validation: Check for valid inputs wherever necessary, especially in ADD and SEARCH commands.
Dynamic Replacement: For the PhoneBook class, you can use an array of Contact objects and a counter to keep track of the current number of contacts. When adding the 9th contact, overwrite the oldest one.



