#pragma once

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {

	private :

		const std::string 	_name;
		bool				_isSigned;
		const int 			_sign;
		const int 			_exec;
	
	public :

		Form( std::string name , int Signed, int exec );
		~Form();
		Form( const Form &src );
		Form &operator=( const Form &rhs );

		std::string getName( void ) const;
		int			getSign( void ) const;
		int			getExec( void ) const;
		bool		getSigned( void ) const;
		
		void		beSigned( Bureaucrat &e );

		class GradeTooHighException : public std::exception 
		{
			virtual const char* what() const throw()
			{
				return ( "Form's grade is too high.\nIt must be between 1 and 150." );
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ( "Form's grade is too low.\nIt must be between 1 and 150." );
			}
		};
};

std::ostream &operator<<( std::ostream &os, const Form &rhs );
