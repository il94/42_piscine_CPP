#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[1;32m[ScavTrap]\033[0m Parameters constructor called. " << _name << " was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src){
	std::cout << "\033[1;32m[ScavTrap]\033[0m Copy constructor called. " << src._name << " has been copied." << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(){
	std::cout << "\033[1;32m[ScavTrap]\033[0m Destructor called. " << _name << " was destroyed." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src){
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;32mScavTrap\033[0m " << _name << " is dead... " << std::endl;
	else if (not this->hasEnergyPoints())
		std::cout << "\033[1;32mScavTrap\033[0m " << _name << " has no energy points... " << std::endl;
	else
	{
		std::cout << "OMG \033[1;32mScavTrap\033[0m " << _name << " attacks " << target << " ! ";
		std::cout << target << " lost " << _attackDamage << " hitpoints." << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate( void )
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;32mScavTrap\033[0m " << _name << " is dead... " << std::endl;
	else
		std::cout << "OOOMMMMGGGGG \033[1;32mScavTrap\033[0m " << _name << " transforms into a Super Sayian !!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "\033[1;32m[ScavTrap]\033[0m Default constructor called" << std::endl;
}