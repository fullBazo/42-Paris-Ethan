#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_p;
		static const int	_frac_bits;

	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );
		Fixed( Fixed const & copy );
		Fixed & operator=( const Fixed & rhs );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		
};

std::ostream &	operator<<( std::ostream & os, Fixed const & rhs  );

#endif