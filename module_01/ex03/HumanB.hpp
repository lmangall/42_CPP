#ifndef HumanB_HPP
# define HumanB_HPP

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon* _weapon;

  public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);

};


// HumanB and HumanB are almost the same except for these two tiny details:
// • While HumanB takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanB will always be armed.

#endif