#include "Fixed.hpp"

int main( void )
{
	std::cout << "=== Constructeurs ===" << std::endl;
	Fixed def;
	Fixed fromInt( 10 );
	Fixed fromFloat( 10.05f );
	Fixed copy( fromFloat );

	std::cout << "def        = " << def << std::endl;
	std::cout << "fromInt    = " << fromInt << std::endl;
	std::cout << "fromFloat  = " << fromFloat << std::endl;
	std::cout << "copy       = " << copy << std::endl;

	std::cout << "\n=== toInt / toFloat ===" << std::endl;
	std::cout << "fromFloat.toInt()   = " << fromFloat.toInt() << std::endl;
	std::cout << "fromFloat.toFloat() = " << fromFloat.toFloat() << std::endl;

	std::cout << "\n=== Assignation ===" << std::endl;
	Fixed assigned;
	assigned = fromFloat;
	std::cout << "assigned = " << assigned << std::endl;

	std::cout << "\n=== Comparaisons ===" << std::endl;
	Fixed a( 5.0f );
	Fixed b( 10.0f );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a > b  : " << (a > b) << std::endl;
	std::cout << "a < b  : " << (a < b) << std::endl;
	std::cout << "a >= a : " << (a >= a) << std::endl;
	std::cout << "a <= a : " << (a <= a) << std::endl;
	std::cout << "a == a : " << (a == a) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "\n=== Arithmetique ===" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	Fixed x( 5.05f );
	Fixed y( 2 );
	std::cout << "5.05f * 2 = " << (x * y) << std::endl;
	std::cout << "5.05f / 2 = " << (x / y) << std::endl;

	std::cout << "\n=== Increment / Decrement ===" << std::endl;
	Fixed c( 1.0f );
	std::cout << "c        = " << c << std::endl;
	std::cout << "++c      = " << (++c) << std::endl;
	std::cout << "c        = " << c << std::endl;
	std::cout << "c++      = " << (c++) << std::endl;
	std::cout << "c        = " << c << std::endl;
	std::cout << "--c      = " << (--c) << std::endl;
	std::cout << "c        = " << c << std::endl;
	std::cout << "c--      = " << (c--) << std::endl;
	std::cout << "c        = " << c << std::endl;

	std::cout << "\n=== min / max (non-const) ===" << std::endl;
	Fixed n1( 3.0f );
	Fixed n2( 7.0f );
	std::cout << "min(n1, n2) = " << Fixed::min( n1, n2 ) << std::endl;
	std::cout << "max(n1, n2) = " << Fixed::max( n1, n2 ) << std::endl;

	std::cout << "\n=== min / max (const) ===" << std::endl;
	Fixed const cn1( 3.0f );
	Fixed const cn2( 7.0f );
	std::cout << "min(cn1, cn2) = " << Fixed::min( cn1, cn2 ) << std::endl;
	std::cout << "max(cn1, cn2) = " << Fixed::max( cn1, cn2 ) << std::endl;

	return 0;
}