#include "../include/type.h"

int	main( void )
{
	srand(time(NULL));
	Base*	base1 = generate();
	Base*	base2 = generate();
	Base*	base3 = generate();

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	identify(base1);
	identify(base2);
	identify(base3);
	std::cout << std::endl;

	identify(NULL);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	identify(*base1);
	identify(*base2);
	identify(*base3);	
	return (0);
}