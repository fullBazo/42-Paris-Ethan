#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {

	private :

		const std::string	_name;
		bool				_isSigned;
		const int			_sign;
		const int			_exec;

	public :

		Form( const std::string name, int sign, int exec );
		~Form();
		Form( const Form &src );
		Form &operator=( const Form &rhs );

		std::string	getName( void ) const;
		int			getSign( void ) const;
		int			getExec( void ) const;
		bool		getSigned( void ) const;

		void		beSigned( const Bureaucrat &b );

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const Form &rhs );

#endif
