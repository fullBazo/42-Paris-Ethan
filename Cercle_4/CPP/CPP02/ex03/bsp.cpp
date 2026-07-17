#include "Fixed.hpp"
#include "Point.hpp"

Fixed	Point::cross(Point const a, Point const b, Point const c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((b.getY() - a.getY()) * (c.getX() - a.getX()));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	
}
