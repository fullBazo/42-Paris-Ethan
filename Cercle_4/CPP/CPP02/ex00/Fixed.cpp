#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _fixed_p(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;

	if ( this != &rhs )
		this->_fixed_p = rhs.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _fixed_p;
}

void Fixed::setRawBits(int const raw)
{
	_fixed_p = raw;
}