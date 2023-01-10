#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :

	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap&);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap&);

	using ScavTrap::attack;

	void	whoAmI( void );

	private :

	DiamondTrap();

	std::string	_name;
};

#endif