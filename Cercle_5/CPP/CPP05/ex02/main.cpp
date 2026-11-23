#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

static void	title( const std::string &s )
{
	std::cout << "\n--- " << s << " ---" << std::endl;
}

int	main( void )
{
	std::srand( std::time( NULL ) );

	try
	{
		Bureaucrat	boss( "Boss", 1 );
		Bureaucrat	clerk( "Clerk", 130 );
		Bureaucrat	intern( "Intern", 140 );
		Bureaucrat	nobody( "Nobody", 150 );

		ShrubberyCreationForm	shrub( "home" );
		RobotomyRequestForm		robot( "Bender" );
		PresidentialPardonForm	pardon( "Arthur" );

		title( "Execute before signing" );
		boss.executeForm( shrub );

		title( "Sign with too low grade" );
		nobody.signForm( shrub );

		title( "Shrubbery: sign OK, execute grade too low" );
		clerk.signForm( shrub );
		std::cout << shrub << std::endl;
		intern.executeForm( shrub );

		title( "Shrubbery: execute OK (creates home_shrubbery)" );
		clerk.executeForm( shrub );

		title( "Robotomy: several executions" );
		boss.signForm( robot );
		for ( int i = 0; i < 4; i++ )
			boss.executeForm( robot );

		title( "Presidential pardon" );
		clerk.signForm( pardon );
		boss.signForm( pardon );
		boss.executeForm( pardon );

		title( "Polymorphism through AForm pointer" );
		AForm	*f = new PresidentialPardonForm( "Ford" );
		boss.signForm( *f );
		boss.executeForm( *f );
		delete f;
	}
	catch ( std::exception &e )
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}
