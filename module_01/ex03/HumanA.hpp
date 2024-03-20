#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon& _weapon;// reference to a Weapon object

  public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();

};


// HumanB and HumanB are almost the same except for these two tiny details:
// • While HumanB takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanB will always be armed.

#endif