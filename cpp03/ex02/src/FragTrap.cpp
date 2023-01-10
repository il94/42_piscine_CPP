#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\033[1;31m[FragTrap]\033[0m Parameters constructor called. " << _name << " was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src){
	std::cout << "\033[1;31m[FragTrap]\033[0m Copy constructor called. " << src._name << " has been copied." << std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "\033[1;31m[FragTrap]\033[0m Destructor called. " << _name << " was destroyed." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src){
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;31mFragTrap\033[0m " << _name << " is dead... " << std::endl;
	else
	{
		std::cout << "\033[1;31mFragTrap\033[0m " << _name << " say : " << std::endl;
		std::cout << "HIGH FIVES BRO DUDE !! \\(^_^)" << std::endl;
	}
}

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "\033[1;31m[FragTrap]\033[0m Default constructor called" << std::endl;
}