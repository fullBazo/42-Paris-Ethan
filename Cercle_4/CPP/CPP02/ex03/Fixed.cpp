#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed( void ) : _value(0){};

Fixed::Fixed( int const value ) 
{
	_value = value << _frac_bits;

	return;
};

Fixed::Fixed( float const value )
{
	_value = roundf(value * (1 << _frac_bits));

	return;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;

	return;
}

float Fixed::toFloat( void ) const
{
	return (float)(_value) / (float)(1 << _frac_bits);
}

int Fixed::toInt( void ) const
{
	return _value / (1 << _frac_bits);
}

int		Fixed::getValue( void ) const
{
	return	_value;
}
void	Fixed::setValue( int const value)
{
	_value = value;

	return;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{

	if ( this != &rhs )
		this->_value = rhs.getValue();

	return *this;
}

Fixed	Fixed::operator+( const Fixed & rhs ) const
{
	return (toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( const Fixed & rhs ) const
{
	return (toFloat() - rhs.toFloat());
}

Fixed 	Fixed::operator*( const Fixed & rhs ) const 
{
	return (toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( const Fixed & rhs ) const
{
	return (toFloat() / rhs.toFloat());
}

bool	Fixed::operator>( const Fixed & rhs ) const
{
	return ( _value > rhs.getValue() );
}

bool 	Fixed::operator<( const Fixed & rhs ) const
{
	return ( _value < rhs.getValue() );
}

bool 	Fixed::operator>=( const Fixed & rhs ) const
{
	return ( _value >= rhs.getValue() );
}

bool 	Fixed::operator<=( const Fixed & rhs ) const
{
	return ( _value <= rhs.getValue() );
}

bool 	Fixed::operator==( const Fixed & rhs ) const
{
	return ( _value == rhs.getValue() );
}

bool 	Fixed::operator!=( const Fixed & rhs ) const
{
	return ( _value != rhs.getValue() );
}

Fixed & Fixed::operator++( void )
{
	++_value;

	return *this;
}

Fixed   Fixed::operator++( int )
{
	Fixed tmp( *this);
	_value++;

	return tmp;
}

Fixed & Fixed::operator--( void )
{
	--_value;

	return *this;
}

Fixed   Fixed::operator--( int )
{
	Fixed tmp( *this);
	_value--;

	return tmp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return a;
	else
		return b;
}
Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	else
		return b;
}
Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	else
		return b;
}

std::ostream &	operator<<( std::ostream & os, Fixed const & rhs  )
{
	os << rhs.toFloat();

	return os;
}

Fixed::~Fixed()
{
	return;
}