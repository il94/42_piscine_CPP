#include "../include/MateriaCure.hpp"

/*=============================== Constructors ===============================*/

MateriaCure::MateriaCure() : A_Materia("cure"){
	std::cout << "[MateriaCure] Default constructor called." << std::endl;
	std::cout << getType() << " was created." << std::endl;
}

MateriaCure::MateriaCure(const MateriaCure &src) : A_Materia(src){
	std::cout << "[MateriaCure] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied." << std::endl;
}

MateriaCure::~MateriaCure(){
	std::cout << "[MateriaCure] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

MateriaCure& MateriaCure::operator=(const MateriaCure &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

A_Materia*	MateriaCure::clone( void ) const
{
	A_Materia*	newMateria = new MateriaCure;

	return (newMateria);
}

void	MateriaCure::use(I_Character& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}