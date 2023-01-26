#include "../include/Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main( void )
{
	Fixed a( 1 );
	Fixed b( 50.5f );

	Fixed const c( 0 );
	Fixed const d( 999.499f );

	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	std::cout << "[A] is " << a;
	std::cout << " || [B] is " << b;
	std::cout << " || [C] is " << c;
	std::cout << " || [D] is " << d << std::endl;

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	std::cout << "[A < B] is [" << a << " < " << b << "] is " << (a < b) << std::endl;
	std::cout << "[A > B] is [" << a << " > " << b << "] is " << (a > b) << std::endl;
	std::cout << std::endl;
	std::cout << "[A <= A] is [" << a << " <= " << a << "] is " << (a <= a) << std::endl;
	std::cout << "[A >= A] is [" << a << " >= " << a << "] is " << (a >= a) << std::endl;
	std::cout << std::endl;
	std::cout << "[A == A] is [" << a << " == " << a << "] is " << (a == a) << std::endl;
	std::cout << "[A != A] is [" << a << " != " << a << "] is " << (a != a) << std::endl;

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	std::cout << "[A + A] is [" << a << " + " << a << "] is " << (a + a) << std::endl;
	std::cout << "[A - A] is [" << a << " - " << a << "] is " << (a - a) << std::endl;
	std::cout << "[A * A] is [" << a << " * " << a << "] is " << (a * a) << std::endl;
	std::cout << "[A / A] is [" << a << " / " << a << "] is " << (a / a) << std::endl;

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	std::cout << "[A++] is " << a++ << " -> " << a << std::endl;
	std::cout << "[A--] is " << a-- << " -> " << a << std::endl;
	std::cout << std::endl;
	std::cout << "[++A] is " << ++a << " -> " << a << std::endl;
	std::cout << "[--A] is " << --a << " -> " << a << std::endl;

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	std::cout << "[A min B] is [" << a << " min " << b << "] is " << Fixed::min( a, b ) << std::endl;
	std::cout << "[A max B] is [" << a << " max " << b << "] is " << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	std::cout << "[C min D] is [" << c << " min " << d << "] is " << Fixed::min( c, d ) << std::endl;
	std::cout << "[C max D] is [" << c << " max " << d << "] is " << Fixed::max( d, d ) << std::endl;

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;

	return (0);
}