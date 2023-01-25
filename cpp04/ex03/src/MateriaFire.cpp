#include "../include/MateriaFire.hpp"

/*=============================== Constructors ===============================*/

MateriaFire::MateriaFire() : A_Materia("fire"){
	std::cout << "[MateriaFire] Default constructor called." << std::endl;
	std::cout << getType() << " was created." << std::endl;
}

MateriaFire::MateriaFire(const MateriaFire &src) : A_Materia(src){
	std::cout << "[MateriaFire] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied." << std::endl;
}

MateriaFire::~MateriaFire(){
	std::cout << "[MateriaFire] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

MateriaFire& MateriaFire::operator=(const MateriaFire &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

A_Materia*	MateriaFire::clone( void ) const
{
	A_Materia*	newMateria = new MateriaFire;

	return (newMateria);
}

void	MateriaFire::use(I_Character& target)
{
	std::cout << "* shoots an fire bolt at " << target.getName() << " *" << std::endl;
}

/*================================ Accessors =================================*/


