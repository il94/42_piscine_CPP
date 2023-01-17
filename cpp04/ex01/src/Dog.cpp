#include "../include/Dog.hpp"

/*=============================== Constructors ===============================*/

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Default constructor called." << std::endl;
	std::cout << getType() << " was created" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied" << std::endl;
}

Dog::~Dog(){
	std::cout << "[Dog] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

Dog& Dog::operator=(const Dog &src)
{
	_type = src._type;
	*_brain = (*src._brain);
	return (*this);
}

/*================================= Methods ==================================*/

void	Dog::makeSound( void ) const
{
	std::cout << "WOUF WOUF" << std::endl;
}
