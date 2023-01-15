#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << name << " is invalid" << std::endl;
		return (NULL);
	}
	try
	{
		Zombie *zombie = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombie[i].setName(name);
		return (zombie);
	}
	catch(std::bad_alloc&) 
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
}
