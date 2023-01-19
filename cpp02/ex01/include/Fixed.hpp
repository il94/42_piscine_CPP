#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed
{
	public :
	
	Fixed();
	Fixed(const int bits);
	Fixed(const float bits);
	Fixed(const Fixed&);
	~Fixed();

	Fixed&	operator=(const Fixed&);

	int 	getRawBits( void ) const;
	void 	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	private :

	int					_value;
	static const int	_BITS = 8;
};

std::ostream&	operator<<(std::ostream &flow, Fixed const &value);

#endif