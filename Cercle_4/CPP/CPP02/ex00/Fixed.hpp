#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_p;
		static const int	_frac_bits;

	public:
		Fixed( void );
		~Fixed( void );
		Fixed( Fixed const & copy );
		Fixed & operator=( const Fixed & rhs );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif