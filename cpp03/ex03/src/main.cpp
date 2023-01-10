#include "../include/DiamondTrap.hpp"

int	main( void )
{
	ClapTrap	yamcha("Yamcha");
	yamcha.printAttributes();
	std::cout << std::endl;

	ScavTrap	vegeta("Vegeta");
	vegeta.printAttributes();
	std::cout << std::endl;

	FragTrap	gohan("Gohan");
	gohan.printAttributes();
	std::cout << std::endl;

	DiamondTrap	goku("Goku");
	goku.printAttributes();
	std::cout << std::endl;

	goku.attack("God Usopp");
	goku.attack("God Usopp");
	goku.attack("God Usopp");
	std::cout << "God Usopp will end it soon..." << std::endl;
	std::cout << std::endl;

	goku.takeDamage(99);
	goku.beRepaired(1000);
	goku.beRepaired(2000);
	goku.beRepaired(5000);
	goku.beRepaired(10000);
	goku.beRepaired(20000);
	goku.beRepaired(50000);
	goku.beRepaired(100000);
	goku.beRepaired(150000);
	goku.beRepaired(150000);
	goku.attack("God Usopp");
	std::cout << std::endl;
	
	vegeta.guardGate();
	std::cout << "...But we don't really know why ?" << std::endl;
	std::cout << std::endl;

	gohan.highFivesGuys();
	std::cout << "You : " << std::endl;
	std::cout << "YEAH THAT'S MY BRO DUDE (^_^)/" << std::endl;
	std::cout << std::endl;

	goku.guardGate();
	goku.highFivesGuys();
	std::cout << "GOKU IS INCREDIBLE !! IT'S OVER 9000 !!!" << std::endl;
	goku.whoAmI();
	std::cout << std::endl;

	std::cout << "God Ussop say :" << std::endl << "I have to go home, so..." << std::endl;
	goku.takeDamage(99999999);
	vegeta.takeDamage(99999999);
	gohan.takeDamage(99999999);
	goku.beRepaired(1);
	vegeta.attack("God Usopp");
	gohan.highFivesGuys();
	std::cout << "God Usopp has destroyed everyone..." << std::endl;
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
		FragTrap	gohanCopy(gohan);
	}
		std::cout << std::endl;
	{
		DiamondTrap	gokuCopy(goku);
	}
	std::cout << std::endl;
	return (0);
}