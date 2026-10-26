#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

Form::Form( const std::string name, int sign, int exec )
	: _name( name ), _isSigned( false ), _sign( sign ), _exec( exec )
{
	if ( _sign < 1 || _exec < 1 )
		throw Form::GradeTooHighException();
	if ( _sign > 150 || _exec > 150 )
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form( const Form &src )
	: _name( src._name ), _isSigned( src._isSigned ), _sign( src._sign ), _exec( src._exec )
{
}

Form &Form::operator=( const Form &rhs )
{
	if ( this != &rhs )
		_isSigned = rhs._isSigned;
	return *this;
}

std::string Form::getName( void ) const
{
	return _name;
}

int Form::getSign( void ) const
{
	return _sign;
}

int Form::getExec( void ) const
{
	return _exec;
}

bool Form::getSigned( void ) const
{
	return _isSigned;
}

void Form::beSigned( const Bureaucrat &b )
{
	if ( b.getGrade() > _sign )
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<( std::ostream &os, const Form &rhs )
{
	os << "Form " << rhs.getName()
		<< " (signed: " << ( rhs.getSigned() ? "yes" : "no" )
		<< ", grade to sign: " << rhs.getSign()
		<< ", grade to execute: " << rhs.getExec() << ")";
	return os;
}
