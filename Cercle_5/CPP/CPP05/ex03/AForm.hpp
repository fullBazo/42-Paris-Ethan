#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {

	private :

		const std::string	_name;
		bool				_isSigned;
		const int			_sign;
		const int			_exec;

	protected :

		// Action specifique a chaque formulaire concret.
		virtual void	action( void ) const = 0;

	public :

		AForm( const std::string name, int sign, int exec );
		virtual ~AForm();
		AForm( const AForm &src );
		AForm &operator=( const AForm &rhs );

		std::string	getName( void ) const;
		int			getSign( void ) const;
		int			getExec( void ) const;
		bool		getSigned( void ) const;

		void		beSigned( const Bureaucrat &b );
		void		execute( const Bureaucrat &executor ) const;

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

		class FormNotSignedException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const AForm &rhs );

#endif
