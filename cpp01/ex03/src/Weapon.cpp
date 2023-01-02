#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

const std::string&	Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}
