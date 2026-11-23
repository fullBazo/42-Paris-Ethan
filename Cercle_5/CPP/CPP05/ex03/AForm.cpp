#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "the form is not signed";
}

AForm::AForm( const std::string name, int sign, int exec )
	: _name( name ), _isSigned( false ), _sign( sign ), _exec( exec )
{
	if ( _sign < 1 || _exec < 1 )
		throw AForm::GradeTooHighException();
	if ( _sign > 150 || _exec > 150 )
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm( const AForm &src )
	: _name( src._name ), _isSigned( src._isSigned ), _sign( src._sign ), _exec( src._exec )
{
}

AForm &AForm::operator=( const AForm &rhs )
{
	if ( this != &rhs )
		_isSigned = rhs._isSigned;
	return *this;
}

std::string AForm::getName( void ) const
{
	return _name;
}

int AForm::getSign( void ) const
{
	return _sign;
}

int AForm::getExec( void ) const
{
	return _exec;
}

bool AForm::getSigned( void ) const
{
	return _isSigned;
}

void AForm::beSigned( const Bureaucrat &b )
{
	if ( b.getGrade() > _sign )
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::execute( const Bureaucrat &executor ) const
{
	if ( !_isSigned )
		throw AForm::FormNotSignedException();
	if ( executor.getGrade() > _exec )
		throw AForm::GradeTooLowException();
	action();
}

std::ostream &operator<<( std::ostream &os, const AForm &rhs )
{
	os << "Form " << rhs.getName()
		<< " (signed: " << ( rhs.getSigned() ? "yes" : "no" )
		<< ", grade to sign: " << rhs.getSign()
		<< ", grade to execute: " << rhs.getExec() << ")";
	return os;
}
