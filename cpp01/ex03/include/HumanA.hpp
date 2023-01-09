#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA
{
	public :

	HumanA(std::string name, Weapon &weapon);

	void	attack();

	private :

	std::string _name;
	Weapon		&_weapon;
};

#endif