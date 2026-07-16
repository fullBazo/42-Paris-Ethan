#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed( int const value )
{
	std::cout << "Int constructor called" << std::endl;
	// 00000000 00000000 00000000 , 0000000
	// 
	_fixed_p = value << _frac_bits;

	return;
}

Fixed::Fixed( float const value )
{
	std::cout << "Float constructor called" << std::endl;

	_fixed_p = roundf(value * (1 << _frac_bits));

	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;

	if ( this != &rhs )
		this->_fixed_p = rhs._fixed_p;

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int	Fixed::toInt( void ) const
{
	return _fixed_p >> _frac_bits;
}

float 	Fixed::toFloat( void ) const
{
	return (float)(_fixed_p) / (float)(1 << _frac_bits); 
}

std::ostream&	operator<<( std::ostream & os, Fixed const & rhs  )
{
	os << rhs.toFloat();

	return os;
}