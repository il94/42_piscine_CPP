#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed
{
	public :
	
	/* Constructors */
	Fixed();
	Fixed(const int bits);
	Fixed(const float bits);
	Fixed(const Fixed&);
	~Fixed();

	/* Overloads */
	Fixed&	operator=(const Fixed&);

	bool	operator>(const Fixed &factor) const;
	bool	operator<(const Fixed &factor) const;
	bool	operator>=(const Fixed &factor) const;
	bool	operator<=(const Fixed &factor) const;
	bool	operator==(const Fixed &factor) const;
	bool	operator!=(const Fixed &factor) const;

	Fixed	operator+(const Fixed &factor) const;
	Fixed	operator-(const Fixed &factor) const;
	Fixed	operator*(const Fixed &factor) const;
	Fixed	operator/(const Fixed &factor) const;

	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	/* Methods */
	float			toFloat( void ) const;
	int				toInt( void ) const;
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	min(const Fixed &a, const Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);

	/* Accessors */
	int 			getRawBits( void ) const;
	void 			setRawBits(int const raw);

	private :

	int					_value;
	static const int	_BITS = 8;
};

std::ostream&	operator<<(std::ostream &flow, Fixed const &value);

#endif