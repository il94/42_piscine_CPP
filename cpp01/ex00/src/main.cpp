#include "../include/Zombie.hpp"

Zombie*	 newZombie( std::string name );
void	 randomChump( std::string name );

int main(void)
{
	Zombie *zombie = newZombie("Moussa le brancardier");

	zombie->announce();
	randomChump("Poulai pikante");
	delete zombie;
	return (0);
}