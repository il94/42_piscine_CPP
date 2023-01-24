#include "../include/A_Materia.hpp"

/*=============================== Constructors ===============================*/

A_Materia::A_Materia() : _type("unamed"){
	std::cout << "[A_Materia] Default constructor called." << std::endl;
}

A_Materia::A_Materia(std::string const &type) : _type(type){
	std::cout << "[A_Materia] Parameters constructor called." << std::endl;
}

A_Materia::A_Materia(const A_Materia &src){
	std::cout << "[A_Materia] Copy constructor called." << std::endl;
	*this = src;
}

A_Materia::~A_Materia(){
	std::cout << "[A_Materia] Default destructor called." << std::endl;
	std::cout << getType() << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

A_Materia& A_Materia::operator=(const A_Materia &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

// void	A_Materia::use(I_Character& target)
// {

// }

/*================================ Accessors =================================*/

std::string const&	A_Materia::getType( void ) const{
	return (_type);
}
