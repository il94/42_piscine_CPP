#include "../include/Zombie.hpp"

Zombie* newZombie(std::string name)
{
	try
	{
		Zombie *zombie = new Zombie(name);
		return (zombie);
	}
	catch(std::bad_alloc&) 
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
}