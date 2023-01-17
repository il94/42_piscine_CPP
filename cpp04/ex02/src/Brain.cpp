#include "../include/Brain.hpp"

/*=============================== Constructors ===============================*/

Brain::Brain(){
	std::cout << "[Brain] Default constructor called." << std::endl;
	srand(time(NULL));
	int	i = 0;

	while (i < 2)
		_ideas[i++] = "to destroy the world";
	while (i < 10)
		_ideas[i++] = "to burn the world";
	while (i < 25)
		_ideas[i++] = "to poop in the living room";
	while (i < 40)
		_ideas[i++] = "to be caressed";
	while (i < 60)
		_ideas[i++] = "to sleep";
	while (i < 100)
		_ideas[i++] = "to eat";
}

Brain::Brain(const Brain &src){
	std::cout << "[Brain] Copy constructor called." << std::endl;
	*this = src;
}

Brain::~Brain(){
	std::cout << "[Brain] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

Brain& Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return (*this);
}

/*================================= Methods ==================================*/

std::string	Brain::getRandomIdea( void ) const
{
	return (_ideas[rand() % 100]);
}


/*================================ Accessors =================================*/


