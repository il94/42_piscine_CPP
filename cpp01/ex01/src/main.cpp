#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombies = zombieHorde(0, "pas bien");
	std::cout << std::endl;

	zombies = zombieHorde(3, "VROUM VROUM LA TUTURE");
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Z" << i << " "; 
		zombies[i].announce();
	}
	std::cout << std::endl;

	delete [] zombies;
	return (0);
}
