#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>


class Zombie
{
private:
	std::string _name;

public:
	Zombie();//default constructor
	~Zombie();
	Zombie(std::string _name);//parameterized constructor
	void announce(void);

};

Zombie*  zombieHorde( int N, std::string name );

#endif