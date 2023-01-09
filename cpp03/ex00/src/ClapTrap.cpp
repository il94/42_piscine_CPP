#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
}

ClapTrap::ClapTrap(const ClapTrap& src){
	*this = src;
}

ClapTrap::~ClapTrap(){
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
	std::cout << "OMG ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << "!" << std::endl;
	std::cout << target << " lost " << _attackDamage << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "WTF ClapTrap " << _name << " take " << amount << " damages !" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "OOoooohhh ClapTrap " << _name << " heals " << amount << " hit points !" << std::endl;
	_hitPoints += amount;
}

ClapTrap::ClapTrap() {
}
