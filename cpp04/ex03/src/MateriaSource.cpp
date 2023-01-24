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
		if (src._inventory[i]->getType() == "Ice")
			_inventory[i] = new MateriaIce;
		else if (src._inventory[i]->getType() == "Cure")
			_inventory[i] = new MateriaCure;
	}

	return (*this);
}

/*================================= Methods ==================================*/

void	MateriaSource::learnMateria(A_Materia* model)
{
	if (_countMaterias < 4)
	{
		if (model->getType() == "Ice" || model->getType() == "Cure")
			_inventory[_countMaterias] = model;
		_countMaterias++;
	}
}

A_Materia*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _countMaterias; i++)
	{
		if (type == _inventory[i]->getType())
			return (_inventory[i]);
	}
	return (0);
}

/*================================ Accessors =================================*/


