#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	_weapon = &newWeapon;
}