#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0){
}

Fixed::Fixed(const int bits) : _value(bits << _BITS){
}

Fixed::Fixed(const float bits) : _value(roundf(bits * (1 << _BITS))){
}

Fixed::Fixed(const Fixed &src){
	*this = src;
}

Fixed::~Fixed(){
}

/*============================================================================*/

Fixed& Fixed::operator=(const Fixed &src)
{
	setRawBits(src._value);
	return (*this);
}

/*============================================================================*/

bool	Fixed::operator>(const Fixed &factor) const
{
	return (getRawBits() > factor.getRawBits());
}

bool	Fixed::operator<(const Fixed &factor) const
{
	return (getRawBits() < factor.getRawBits());
}

bool	Fixed::operator>=(const Fixed &factor) const
{
	return (getRawBits() >= factor.getRawBits());
}

bool	Fixed::operator<=(const Fixed &factor) const
{
	return (getRawBits() <= factor.getRawBits());
}

bool	Fixed::operator==(const Fixed &factor) const
{
	return (getRawBits() == factor.getRawBits());
}

bool	Fixed::operator!=(const Fixed &factor) const
{
	return (getRawBits() != factor.getRawBits());
}

/*============================================================================*/

Fixed	Fixed::operator+(const Fixed &factor) const
{
	Fixed	result;

	result.setRawBits(getRawBits() + factor.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &factor) const
{
	Fixed	result;

	result.setRawBits(getRawBits() - factor.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &factor) const
{
	Fixed	result;

	result.setRawBits(getRawBits() * factor.toInt());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &factor) const
{
	Fixed	result;

	result.setRawBits(getRawBits() / factor.toInt());
	return (result);
}

/*============================================================================*/

Fixed&	Fixed::operator++( void )
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	result;

	result = *this;
	setRawBits(getRawBits() + 1);
	return (result);
}

Fixed&	Fixed::operator--( void )
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	result;

	result = *this;
	setRawBits(getRawBits() - 1);
	return (result);
}

/*============================================================================*/

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _BITS));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _BITS);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

/*============================================================================*/

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

/*============================================================================*/

std::ostream&	operator<<(std::ostream &flow, Fixed const &value)
{
	flow << value.toFloat();
	return (flow);
}