#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int bits) : _value(bits << _BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float bits) : _value(roundf(bits * (1 << _BITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	setRawBits(src._value);
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _BITS));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _BITS);
}

std::ostream&	operator<<(std::ostream &flow, Fixed const &value)
{
	flow << value.toFloat();
	return (flow);
}