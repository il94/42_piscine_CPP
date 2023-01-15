#include "../include/Zombie.hpp"

Zombie::Zombie(){
}

Zombie::Zombie(std::string name) : _name(name){
}

Zombie::~Zombie(){
	std:: cout << _name << " was deleted" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}