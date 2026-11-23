#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

static void	title( const std::string &s )
{
	std::cout << "\n--- " << s << " ---" << std::endl;
}

// int	main( void )
// {
// 	std::srand( std::time( NULL ) );

// 	try
// 	{
// 		Intern		someRandomIntern;
// 		Bureaucrat	boss( "Boss", 1 );
// 		AForm		*form;

// 		title( "Robotomy request (example from the subject)" );
// 		form = someRandomIntern.makeForm( "robotomy request", "Bender" );
// 		if ( form )
// 		{
// 			std::cout << *form << std::endl;
// 			boss.signForm( *form );
// 			boss.executeForm( *form );
// 			delete form;
// 		}

// 		title( "Presidential pardon" );
// 		form = someRandomIntern.makeForm( "presidential pardon", "Arthur" );
// 		if ( form )
// 		{
// 			boss.signForm( *form );
// 			boss.executeForm( *form );
// 			delete form;
// 		}

// 		title( "Shrubbery creation (creates garden_shrubbery)" );
// 		form = someRandomIntern.makeForm( "shrubbery creation", "garden" );
// 		if ( form )
// 		{
// 			boss.signForm( *form );
// 			boss.executeForm( *form );
// 			delete form;
// 		}

// 		title( "Unknown form name" );
// 		form = someRandomIntern.makeForm( "coffee order", "Boss" );
// 		if ( !form )
// 			std::cout << "No form was created." << std::endl;
// 		else
// 			delete form;

// 		title( "Empty form name" );
// 		form = someRandomIntern.makeForm( "", "Nobody" );
// 		if ( form )
// 			delete form;
// 	}
// 	catch ( std::exception &e )
// 	{
// 		std::cout << "Unexpected exception: " << e.what() << std::endl;
// 	}
// 	return 0;
// }

int	main( void )
{
	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}