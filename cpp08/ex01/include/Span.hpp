#ifndef SPAN
#define SPAN

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public :

	class SpanException : public std::exception
	{
		public :
		virtual const char* what( void ) const throw() = 0;
	};
	class EmptySpan : public SpanException
	{
		public :
		const char* what( void ) const throw() { return ("[Exception] Span is empty"); }
	};
	class FullSpan : public SpanException
	{
		public :
		const char* what( void ) const throw() { return ("[Exception] Span is full"); }
	};


	class iterator
	{
		public :

		/* Constructors */
		iterator( std::vector<int>::iterator );
		iterator(const Span&);
		~iterator();

		/* Overloads */
		iterator&	operator=(const iterator&);
		int 		operator*( void );

		bool		operator==(const iterator &) const;
		bool		operator!=(const iterator &) const;

		iterator& 	operator++( void );
		iterator& 	operator--( void );


		private:

		/* Constructors */
		iterator();

		/* Attributes */
		std::vector<int>::iterator	_value;

	};

	/* Constructors */
	Span( unsigned int );
	Span(const Span&);
	~Span();

	/* Overloads */
	Span&	operator=(const Span&);

	/* Methods */
	void	addNumber( int );
	int		shortestSpan( void );
	int		longestSpan( void );

	/* Iterators */
	iterator	begin( void );
	iterator	end( void );


	private :

	/* Constructors */
	Span();

	/* Attributes */
	std::vector<int>	_container;
	std::vector<int>	_containerSorted;
	size_t				_size;
};

#endif