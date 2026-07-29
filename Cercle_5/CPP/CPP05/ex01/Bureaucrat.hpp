#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat {

	private :

		const std::string	 _name;
		int					_grade;

	public :

		Bureaucrat( std::string name, int grade );
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
			virtual const char* what() const throw()
			{
				return ( "Bureaucrat's grade is too high.\nIt must be between 1 and 150." );
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ( "Bureaucrat's grade is too low.\nIt must be between 1 and 150." );
			}
		};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif
