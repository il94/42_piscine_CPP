#include "../include/A_Animal.hpp"

/*=============================== Constructors ===============================*/

A_Animal::A_Animal() : _type("Meta"), _brain(new Brain){
	std::cout << "[A_Animal] Default constructor called." << std::endl;
}

A_Animal::A_Animal(std::string type) : _type(type), _brain(new Brain){
	std::cout << "[A_Animal] Parameters constructor called." << std::endl;
}

A_Animal::A_Animal(const A_Animal &src) : _brain(new Brain){
	std::cout << "[A_Animal] Copy constructor called." << std::endl;
	*this = src;
}

A_Animal::~A_Animal(){
	std::cout << "[A_Animal] Default destructor called." << std::endl;
	delete _brain;
	std::cout << getType() << " was destroyed" << std::endl;
}

/*================================ Overloads =================================*/

A_Animal& A_Animal::operator=(const A_Animal &src)
{
	_type = src._type;
	*_brain = *(src._brain);
	return (*this);
}

/*================================= Methods ==================================*/

void	A_Animal::wants( void ) const
{
	std::cout << getType() << " wants " <<  _brain->getRandomIdea() << std::endl;
}

/*================================ Accessors =================================*/

std::string	A_Animal::getType( void ) const {
	return (_type);
}
