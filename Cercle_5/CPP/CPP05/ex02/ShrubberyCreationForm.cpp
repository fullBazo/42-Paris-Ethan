#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target( target )
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src )
	: AForm( src ), _target( src._target )
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs )
{
	if ( this != &rhs )
	{
		AForm::operator=( rhs );
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::action( void ) const
{
	std::ofstream file( ( _target + "_shrubbery" ).c_str() );

	if ( !file.is_open() )
		throw std::runtime_error( "cannot create the shrubbery file" );

	file << "       _-_\n"
		 << "    /~~   ~~\\\n"
		 << " /~~         ~~\\\n"
		 << "{               }\n"
		 << " \\  _-     -_  /\n"
		 << "   ~  \\\\ //  ~\n"
		 << "_- -   | | _- _\n"
		 << "  _ -  | |   -_\n"
		 << "      // \\\\\n"
		 << "\n"
		 << "    ^\n"
		 << "   /|\\\n"
		 << "  /_|_\\\n"
		 << "   /|\\\n"
		 << "  /_|_\\\n"
		 << " /__|__\\\n"
		 << "    |\n"
		 << "    |\n";
}
