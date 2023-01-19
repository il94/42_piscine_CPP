#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
	public :
	
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);
	~Fixed();

	int 	getRawBits( void ) const;
	void 	setRawBits(int const raw);

	private :

	int					_value;
	static const int	_BITS = 8;
};

#endif