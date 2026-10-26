#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat {

	private :

		const std::string	_name;
		int					_grade;

	public :

		Bureaucrat( const std::string name, int grade );
		~Bureaucrat();
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat &operator=( const Bureaucrat &rhs );

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );

		void	signForm( Form &form );

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

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif
