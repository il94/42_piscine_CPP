#include "../include/MateriaSource.hpp"

/*=============================== Constructors ===============================*/

MateriaSource::MateriaSource() : I_MateriaSource(), _countMaterias(0){
	std::cout << "[MateriaSource] Default constructor called." << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) : I_MateriaSource(), _countMaterias(0){
	std::cout << "[MateriaSource] Copy constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(){
	std::cout << "[MateriaSource] Default destructor called." << std::endl;
	for (int i = 0; i < _countMaterias; i++)
		delete _inventory[i];
}

/*================================ Overloads =================================*/

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < _countMaterias; i++)
	{
		delete _inventory[i];
		if (src._inventory[i]->getType() == "ice")
			_inventory[i] = new MateriaIce;
		else if (src._inventory[i]->getType() == "cure")
			_inventory[i] = new MateriaCure;
		else if (src._inventory[i]->getType() == "fire")
			_inventory[i] = new MateriaFire;
		else if (src._inventory[i]->getType() == "lightning")
			_inventory[i] = new MateriaLightning;
	}

	return (*this);
}

/*================================= Methods ==================================*/

void	MateriaSource::learnMateria(A_Materia* model)
{
	if (_countMaterias < 4)
	{
		_inventory[_countMaterias] = model;
		_countMaterias++;
	}
	else
		delete model;
}

A_Materia*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; _countMaterias <= 4 and i < _countMaterias; i++)
	{
		if (type == _inventory[i]->getType())
		{
			if (_inventory[i]->getType() == "ice")
				return (new MateriaIce);
			else if (_inventory[i]->getType() == "cure")
				return (new MateriaCure);
			else if (_inventory[i]->getType() == "fire")
				return (new MateriaFire);
			else if (_inventory[i]->getType() == "lightning")
				return (new MateriaLightning);
		}
	}
	return (0);
}