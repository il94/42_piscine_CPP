#ifndef	CLAPTRAP
#define	CLAPTRAP

#include <iostream>
#include <string>

class ClapTrap
{
	public:

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap&);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap&);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	private:

	ClapTrap();
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};


#endif