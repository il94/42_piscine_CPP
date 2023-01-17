#include "../include/MateriaIce.hpp"

/*=============================== Constructors ===============================*/

MateriaIce::MateriaIce() : A_Materia("Ice"){
	std::cout << "[MateriaIce] Default constructor called." << std::endl;
	std::cout << getType() << " was created." << std::endl;
}

MateriaIce::MateriaIce(const MateriaIce &src) : A_Materia(src){
	std::cout << "[MateriaIce] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied." << std::endl;
}

MateriaIce::~MateriaIce(){
	std::cout << "[MateriaIce] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

MateriaIce& MateriaIce::operator=(const MateriaIce &src)
{
	return (*this);
}

/*================================= Methods ==================================*/

A_Materia*	MateriaIce::clone( void ) const
{
	A_Materia*	newMateria = new MateriaIce;

	return (newMateria);
}

void	MateriaIce::use(I_Character& target)
{
	std::cout << "* shoots an ice bolt at " << "name" << std::endl;
}

/*================================ Accessors =================================*/


