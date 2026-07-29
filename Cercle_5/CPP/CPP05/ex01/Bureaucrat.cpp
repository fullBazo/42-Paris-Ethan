#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade)
{
	if ( _grade < 1 )
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if ( _grade > 150 )
	{
		throw Bureaucrat::GradeTooHighException();
	}
};

Bureaucrat::~Bureaucrat( void ) 
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}		

Bureaucrat::Bureaucrat( const Bureaucrat &src ) 
{
	*this = src;

	return ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &rhs )
{
	if ( this != &rhs )
	{
		_grade = rhs._grade;
	}
	
	return *this;
}

std::string Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade( void ) 
{
	if ( _grade == 1 )
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if ( _grade == 150 )
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade++;
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";

	return os;
}

