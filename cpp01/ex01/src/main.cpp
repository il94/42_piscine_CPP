#include "../include/Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main(void)
{
	Zombie *zombies = zombieHorde(3, "VROUM VROUM LA TUTURE");

	delete [] zombies;
	return (0);
}
