#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int	_frac_bits;
		int					_value;


	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );
		Fixed( Fixed const & copy );
		
		float	toFloat( void ) const;
		int 	toInt( void ) const;
		int		getValue( void ) const;
		void	setValue ( int const value);	


		Fixed & operator=( const Fixed & rhs );
		Fixed	operator+( const Fixed & rhs ) const;
		Fixed	operator-( const Fixed & rhs ) const;
		Fixed 	operator*( const Fixed & rhs ) const;
		Fixed	operator/( const Fixed & rhs ) const;

		bool 	operator>( const Fixed & rhs ) const;
		bool 	operator<( const Fixed & rhs ) const;
		bool 	operator>=( const Fixed & rhs ) const;
		bool 	operator<=( const Fixed & rhs ) const;
		bool 	operator==( const Fixed & rhs ) const;
		bool 	operator!=( const Fixed & rhs ) const;

		Fixed & operator++( void );
		Fixed   operator++( int );
		Fixed & operator--( void );
		Fixed   operator--( int );

		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & min(Fixed const & a, Fixed const & b);
		static const Fixed & max(Fixed const & a, Fixed const & b);
};

std::ostream &	operator<<( std::ostream & os, Fixed const & rhs  );

#endif