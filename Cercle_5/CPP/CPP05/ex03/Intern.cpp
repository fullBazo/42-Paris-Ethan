#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Une fonction de creation par type de formulaire.
static AForm	*createShrubbery( const std::string &target )
{
	return new ShrubberyCreationForm( target );
}

static AForm	*createRobotomy( const std::string &target )
{
	return new RobotomyRequestForm( target );
}

static AForm	*createPardon( const std::string &target )
{
	return new PresidentialPardonForm( target );
}

// Table de correspondance : nom du formulaire -> fonction de creation.
struct FormType
{
	const char	*name;
	AForm		*( *create )( const std::string & );
};

static const FormType	g_formTypes[] = {
	{ "shrubbery creation", &createShrubbery },
	{ "robotomy request", &createRobotomy },
	{ "presidential pardon", &createPardon }
};

static const int	g_formTypesCount = sizeof( g_formTypes ) / sizeof( g_formTypes[0] );

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern( const Intern & )
{
}

Intern &Intern::operator=( const Intern & )
{
	return *this;
}

AForm	*Intern::makeForm( const std::string name, const std::string target ) const
{
	for ( int i = 0; i < g_formTypesCount; i++ )
	{
		if ( name == g_formTypes[i].name )
		{
			std::cout << "Intern creates " << name << std::endl;
			return g_formTypes[i].create( target );
		}
	}
	std::cout << "Intern can't create \"" << name << "\": unknown form name." << std::endl;
	return NULL;
}
