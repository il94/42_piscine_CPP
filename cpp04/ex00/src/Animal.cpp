#include "../include/Animal.hpp"

/*=============================== Constructors ===============================*/

Animal::Animal() : _type("Meta") {
	std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Animal] Parameters constructor called." << std::endl;
}

Animal::Animal(const Animal &src){
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal(){
	std::cout << "[Animal] Default destructor called." << std::endl;
	std::cout << getType() << " was destroyed" << std::endl;
}

/*================================ Overloads =================================*/

Animal& Animal::operator=(const Animal &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

void	Animal::makeSound( void ) const{
}

/*================================ Accessors =================================*/

std::string	Animal::getType( void ) const {
	return (_type);
}
