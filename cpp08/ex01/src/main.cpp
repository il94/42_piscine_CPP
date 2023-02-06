#include "../include/Span.hpp"
#define SIZE_MAX 50

// int	main( void )
// {
// 	Span sp(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	sp.printSpan();

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }

void	printElement(int i){
	std::cout << "[" << i << "] ";
}

int	getRandomNumber( void ){
	return (std::rand() % SIZE_MAX);
}

void	fill(Span &src, int value)
{
	for (Span::iterator it = src.begin(); it != src.end(); ++it)
		src.addNumber(value);
}

void	randomFill(Span &src)
{
	for (Span::iterator it = src.begin(); it != src.end(); ++it)
		src.addNumber(getRandomNumber());
}

int	main( void )
{
	std::srand(time(NULL));

	Span spoun(5);
	std::for_each(spoun.begin(), spoun.end(), printElement);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	randomFill(spoun);
	std::for_each(spoun.begin(), spoun.end(), printElement);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try
	{
		spoun.addNumber(0);
	}
	catch(const Span::SpanException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Shortest span is " << spoun.shortestSpan() << std::endl;
		std::cout << "Longest span is " << spoun.longestSpan() << std::endl;
	}
	catch(const Span::SpanException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cout << "😪 😪 😪 😪 😪 😪 😪" << std::endl;
	Span ultimateSpoun(10000);

	randomFill(ultimateSpoun);
	std::cout << "U Shortest span is " << ultimateSpoun.shortestSpan() << std::endl;
	std::cout << "U Longest span is " << ultimateSpoun.longestSpan() << std::endl;

	return (0);
}