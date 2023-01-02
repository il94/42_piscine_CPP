#include "../include/Zombie.hpp"

Zombie::~Zombie()
{
	std:: cout << _name << " was deleted" << std::endl;
}

void	Zombie::setName(std::string newName)
{
	_name = newName;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}