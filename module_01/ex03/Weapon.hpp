#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(const std::string& type);
    ~Weapon();
	
	//returns a const reference to type
    const std::string& getType() const;
	//sets type using the new one passed as parameter
    void setType(const std::string& newType);
};

#endif 


// The getType function is declared with const at the end of its declaration, 
// indicating that it doesn't modify any member variables of the Weapon class.
// This is important for const correctness.



// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as parameter.