#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :

	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap&);

	void	attack(const std::string& target);
	void	guardGate( void );

	protected :

	ScavTrap();
};

#endif