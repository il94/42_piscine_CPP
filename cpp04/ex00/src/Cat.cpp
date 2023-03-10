#include "../include/Cat.hpp"

/*=============================== Constructors ===============================*/

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called. " << std::endl;
	std::cout << getType() << " was created" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "[Cat] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied" << std::endl;
}

Cat::~Cat(){
	std::cout << "[Cat] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

Cat& Cat::operator=(const Cat &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

void	Cat::makeSound( void ) const
{
	std::cout << "Meeeoooowwwww" << std::endl;
}
