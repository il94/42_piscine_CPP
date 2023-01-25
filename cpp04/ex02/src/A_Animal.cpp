#include "../include/A_Animal.hpp"

/*=============================== Constructors ===============================*/

A_Animal::A_Animal() : _type("Meta"){
	std::cout << "[A_Animal] Default constructor called." << std::endl;
}

A_Animal::A_Animal(std::string type) : _type(type){
	std::cout << "[A_Animal] Parameters constructor called." << std::endl;
}

A_Animal::A_Animal(const A_Animal &src){
	std::cout << "[A_Animal] Copy constructor called." << std::endl;
	*this = src;
}

A_Animal::~A_Animal(){
	std::cout << "[A_Animal] Default destructor called." << std::endl;
	std::cout << getType() << " was destroyed" << std::endl;
}

/*================================ Overloads =================================*/

A_Animal& A_Animal::operator=(const A_Animal &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

void	A_Animal::wants( void ) const{
}

/*================================ Accessors =================================*/

std::string	A_Animal::getType( void ) const {
	return (_type);
}
