#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "\033[1;36m[DiamondTrap]\033[0m Parameters constructor called. " << _name << " was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src){
	std::cout << "\033[1;36m[DiamondTrap]\033[0m Copy constructor called. " << _name << " has been copied." << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "\033[1;36m[DiamondTrap]\033[0m Destructor called. " << _name << " was destroyed." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src){
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI( void )
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;36mDiamondTrap\033[0m " << _name << " is dead... " << std::endl;
	else
	{
		std::cout << "\033[1;36mDiamondTrap\033[0m " << _name << " say : " << std::endl;
		std::cout << "I am... YOUR FATHER !! No it's a joke, my name is " << _name << std::endl;
		std::cout << "But my real name is DIO BRANDO ZEHAHAHA !! No lol, it's " << ClapTrap::_name << std::endl;
	}
}

DiamondTrap::DiamondTrap(){
	std::cout << "\033[1;36m[DiamondTrap]\033[0m Default constructor called" << std::endl;
}