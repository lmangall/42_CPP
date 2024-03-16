
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string> //for std::string


// Contact is a class,
// an instance of the class Contact will be an object
class Contact 
{
private:
	// Private member variables to store contact details
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

//std::string firstName: 
//This parameter takes a std::string object
//to initialize the firstName member variable
//of the Contact object being created.

public:
    // Constructors    (used to initialize objects of a class)
    Contact(); // Default constructor: Creates an empty Contact object.
    //Parameterized constructor: Takes arguments to initialize the contact information.
    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

    // Setters => to modify a class's private member variables from outside the class.
    //            Return type: void (don't return a value)
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    // Getters => Retrieve the values of private member variables from outside the class.
    //            Return type: void (don't return a value)
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
	
};

#endif



// -----On setters and getters-------
// Encapsulation: Setters and getters are fundamental for encapsulation, a core OOP concept. 
//They hide the internal implementation of a class while providing a controlled way to interact with its data.
//
// Data validation: Setters can incorporate data validation 
//to ensure that only valid values are assigned to member variables.
//
// Read-only access: If you only want to allow reading a value without modification,
// you can provide a getter without a corresponding setter.






// Any function implementation put in a header file (except for function templates)
// means 0 to the exercise.
// • You should be able to use each of your headers independently from others. Thus,
// they must include all the dependencies they need. However, you must avoid the
// problem of double inclusion by adding include guards. Otherwise, your grade will
// be 0.