#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "\033[1;33m[ClapTrap]\033[0m Parameters constructor called. " << _name << " was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << "\033[1;33m[ClapTrap]\033[0m Copy constructor called. " << src._name << " has been copied." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(){
	std::cout << "\033[1;33m[ClapTrap]\033[0m Destructor called. " << _name << " was destroyed." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src){
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;33mClapTrap\033[0m " << _name << " is dead... " << std::endl;
	else if (not this->hasEnergyPoints())
		std::cout << "\033[1;33mClapTrap\033[0m " << _name << " has no energy points... " << std::endl;
	else
	{
		std::cout << "OMG \033[1;33mClapTrap\033[0m " << _name << " attacks " << target << " ! ";
		std::cout << target << " lost " << _attackDamage << " hitpoints." << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;33mClapTrap\033[0m " << _name << " is dead... " << std::endl;
	else
	{
		std::cout << "WTF \033[1;33mClapTrap\033[0m " << _name << " take " << amount << " damages !" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (not this->hasHitPoints())
		std::cout << "\033[1;33mClapTrap\033[0m " << _name << " is dead... " << std::endl;
	else if (not this->hasEnergyPoints())
		std::cout << "\033[1;33mClapTrap\033[0m " << _name << " has no energy points... " << std::endl;
	else
	{
		std::cout << "Oooooohhh \033[1;33mClapTrap\033[0m " << _name << " heals " << amount << " hit points !" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

void	ClapTrap::printAttributes( void ){
	std::cout << "_name : [" << _name << "] | _hitPoints : [" << _hitPoints << "] | _energyPoints : [" << _energyPoints << "] | _attackDamage : [" << _attackDamage << "]" << std::endl;
}

bool	ClapTrap::hasHitPoints( void ){
	return (_hitPoints > 0);
}

bool	ClapTrap::hasEnergyPoints( void ){
	return (_energyPoints > 0);
}

ClapTrap::ClapTrap() : _name("unamed"), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
	std::cout << "\033[1;33m[ClapTrap]\033[0m Default constructor called" << std::endl;
}
