#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon& _weapon;

  public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();

};





// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course,
// 	without the
// angle brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.

// If your implementation is correct,
// 	executing the following code will print an attack
// with "crude spiked club" then a second attack with "some other type of club" for both
// test cases:

#endif