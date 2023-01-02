#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB
{
	public :

	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);

	void	attack();
	void	setWeapon(Weapon &newWeapon);

	private :

	std::string _name;
	Weapon		*_weapon;
};

#endif