#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :

	FragTrap(std::string name);
	FragTrap(const FragTrap&);
	~FragTrap();

	FragTrap&	operator=(const FragTrap&);

	void	highFivesGuys( void );

	protected :

	FragTrap();
};

#endif