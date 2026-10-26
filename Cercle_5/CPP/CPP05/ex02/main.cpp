#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout << "--- Bureaucrat: invalid grades ---" << std::endl;
	try { Bureaucrat a( "Zero", 0 ); }
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }
	try { Bureaucrat a( "TooLow", 151 ); }
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }

	std::cout << "\n--- Bureaucrat: increment / decrement ---" << std::endl;
	try
	{
		Bureaucrat a( "Toto", 2 );
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }
	try
	{
		Bureaucrat b( "Titi", 149 );
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }

	std::cout << "\n--- Form: invalid grades ---" << std::endl;
	try { Form f( "Bad", 0, 10 ); }
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }
	try { Form f( "Bad", 10, 151 ); }
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }

	std::cout << "\n--- signForm: success ---" << std::endl;
	try
	{
		Bureaucrat boss( "Boss", 10 );
		Form f( "A38", 20, 5 );
		std::cout << f << std::endl;
		boss.signForm( f );
		std::cout << f << std::endl;
	}
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }

	std::cout << "\n--- signForm: grade too low ---" << std::endl;
	try
	{
		Bureaucrat intern( "Intern", 100 );
		Form f( "B12", 20, 5 );
		intern.signForm( f );
		std::cout << f << std::endl;
	}
	catch ( std::exception &e ) { std::cout << e.what() << std::endl; }

	return 0;
}
