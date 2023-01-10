#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int	main( void )
{
	ClapTrap	yamcha("Yamcha");
	yamcha.printAttributes();
	std::cout << std::endl;

	ScavTrap	vegeta("Vegeta");
	vegeta.printAttributes();
	std::cout << std::endl;

	FragTrap	goku("Goku");
	goku.printAttributes();
	std::cout << std::endl;

	goku.attack("God Usopp");
	goku.attack("God Usopp");
	goku.attack("God Usopp");
	std::cout << "God Usopp takes the blows hoping to feel something..." << std::endl;
	std::cout << std::endl;

	goku.takeDamage(99);
	goku.beRepaired(100);
	goku.beRepaired(200);
	goku.beRepaired(500);
	goku.beRepaired(1000);
	goku.beRepaired(2000);
	goku.beRepaired(5000);
	goku.beRepaired(10000);
	goku.beRepaired(15000);
	goku.beRepaired(15000);
	goku.attack("God Usopp");
	std::cout << std::endl;
	
	vegeta.guardGate();
	std::cout << "...But we don't really know why ?" << std::endl;
	std::cout << std::endl;

	goku.highFivesGuys();
	std::cout << "You : " << std::endl;
	std::cout << "YEAH THAT'S MY BRO DUDE (^_^)/" << std::endl;
	std::cout << std::endl;

	goku.takeDamage(99999);
	vegeta.takeDamage(99999);
	goku.beRepaired(1);
	vegeta.attack("God Usopp");
	std::cout << "God Usopp has pulverized Goku and Vegeta..." << std::endl;
	std::cout << std::endl;

	{
		ClapTrap	yamchaCopy(yamcha);
	}
		std::cout << std::endl;
	{
		ScavTrap	vegetaCopy(vegeta);
	}
		std::cout << std::endl;
	{
		FragTrap	gokuCopy(goku);
	}
	std::cout << std::endl;
	return (0);
}