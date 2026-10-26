#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high (it must be between 1 and 150)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low (it must be between 1 and 150)";
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ), _grade( grade )
{
	if ( _grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( _grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _name( src._name ), _grade( src._grade )
{
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &rhs )
{
	if ( this != &rhs )
		_grade = rhs._grade;
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
	if ( _grade <= 1 )
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if ( _grade >= 150 )
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned( *this );
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}
