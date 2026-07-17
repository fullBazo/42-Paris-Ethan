#include "Point.hpp"


Point::Point(float const a, float const b) : x ( a ) , y ( b ) {};

Fixed Point::getY( void ) const { return y; }

Fixed Point::getX( void ) const { return x; }

Point::Point( Point const & src ) : x ( src.getX() ), y ( src.getY() ) {};

Point & Point::operator=(Point const &rhs)
{
	(void)rhs;
	return *this;
}

Point::~Point( void ) {};
