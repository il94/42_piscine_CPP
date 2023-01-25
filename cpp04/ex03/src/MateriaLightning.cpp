#include "../include/MateriaLightning.hpp"

/*=============================== Constructors ===============================*/

MateriaLightning::MateriaLightning() : A_Materia("lightning"){
	std::cout << "[MateriaLightning] Default constructor called." << std::endl;
	std::cout << getType() << " was created." << std::endl;
}

MateriaLightning::MateriaLightning(const MateriaLightning &src) : A_Materia(src){
	std::cout << "[MateriaLightning] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied." << std::endl;
}

MateriaLightning::~MateriaLightning(){
	std::cout << "[MateriaLightning] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

MateriaLightning& MateriaLightning::operator=(const MateriaLightning &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

A_Materia*	MateriaLightning::clone( void ) const
{
	A_Materia*	newMateria = new MateriaLightning;

	return (newMateria);
}

void	MateriaLightning::use(I_Character& target)
{
	std::cout << "* he brings down the thunder on " << target.getName() << " *" << std::endl;
}

/*================================ Accessors =================================*/


