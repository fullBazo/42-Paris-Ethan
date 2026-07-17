#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
	private : 
		Fixed const x;
		Fixed const y;
	public :
		Point() : x(0), y(0){};
		Point( float const a, float const b );
		Point( Point const & src );
		Point & operator=( Point const & rhs);
		~Point();
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

bool			bsp( Point const a, Point const b, Point const c, Point const point);
Fixed			cross( Point const & a, Point const & b, Point const & c );

#endif