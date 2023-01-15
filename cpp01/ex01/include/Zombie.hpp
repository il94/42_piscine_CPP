#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>

class Zombie
{
	public :

	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce( void );
	void	setName(std::string newName);

	private :

	std::string	_name;
};

#endif