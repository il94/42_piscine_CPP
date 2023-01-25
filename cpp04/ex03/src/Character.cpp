#include "../include/Character.hpp"

/*=============================== Constructors ===============================*/

Character::Character() : _name("unamed"), _countMaterias(0){
	std::cout << "[Character] Default constructor called." << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	std::cout << getName() << " was created." << std::endl;
}

Character::Character(const std::string &name) : _name(name), _countMaterias(0){
	std::cout << "[Character] Parameters constructor called." << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	std::cout << getName() << " was created." << std::endl;
}

Character::Character(const Character &src){
	std::cout << "[Character] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getName() << " was copied." << std::endl;
}

Character::~Character(){
	std::cout << "[Character] Default destructor called." << std::endl;
	for (int i = 0; i < _countMaterias; i++)
		delete _inventory[i];
}

/*================================ Overloads =================================*/

Character& Character::operator=(const Character &src)
{
	_name = src._name;
	_countMaterias = src._countMaterias;

	for (int i = 0; i < _countMaterias; i++)
	{
		delete _inventory[i];
		if (src._inventory[i]->getType() == "ice")
			_inventory[i] = new MateriaIce;
		else if (src._inventory[i]->getType() == "cure")
			_inventory[i] = new MateriaCure;
	}

	return (*this);
}

/*================================= Methods ==================================*/

void	Character::equip(A_Materia* m)
{
	if (_countMaterias < 4)
	{
		_inventory[_countMaterias] = m;
		_countMaterias++;
	}
	else
		delete	m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		for (int i = idx; i < 2; i++)
		{
			_inventory[i] = _inventory[i + 1];
			i++;
			if (i == 2)
				_inventory[i] = NULL;
		}
		/* desequip materia */
	}
}

void	Character::use(int idx, I_Character& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
		_inventory[idx]->use(target);
}

/*================================ Accessors =================================*/

std::string const&	Character::getName( void ) const{
	return (_name);
}

