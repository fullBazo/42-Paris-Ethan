#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private :

		std::string	_target;

		virtual void	action( void ) const;

	public :

		PresidentialPardonForm( const std::string target );
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &rhs );
};

#endif
