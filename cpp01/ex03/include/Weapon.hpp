#ifndef WEAPON
#define WEAPON

#include <iostream>

class Weapon
{
	public :

	Weapon(std::string type);

	const std::string&	getType();
	void				setType(std::string newType);

	private :

	std::string	_type;
};

#endif