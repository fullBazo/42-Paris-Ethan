#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( target )
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src )
	: AForm( src ), _target( src._target )
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs )
{
	if ( this != &rhs )
	{
		AForm::operator=( rhs );
		_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::action( void ) const
{
	std::cout << "* BZZZZZZZZ... VRRRRRRR... *" << std::endl;
	if ( std::rand() % 2 )
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
}
