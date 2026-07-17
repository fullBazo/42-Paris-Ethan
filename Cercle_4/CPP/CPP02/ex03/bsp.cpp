#include "Fixed.hpp"
#include "Point.hpp"

Fixed	cross( Point const & a, Point const & b, Point const & c )
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((b.getY() - a.getY()) * (c.getX() - a.getX()));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	if ( (cross(a, b, c) * cross(a, b, point)) <= Fixed(0) )
		return false;
	if ( (cross(b, c, a) * cross(b, c, point)) <= Fixed(0) )
		return false;
	if ( (cross(c, a, b) * cross(c, a, point)) <= Fixed(0) )
		return false;

	return true;
}
