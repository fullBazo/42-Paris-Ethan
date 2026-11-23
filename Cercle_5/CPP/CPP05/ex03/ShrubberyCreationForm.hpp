#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private :

		std::string	_target;

		virtual void	action( void ) const;

	public :

		ShrubberyCreationForm( const std::string target );
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &rhs );
};

#endif
