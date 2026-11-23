#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private :

		std::string	_target;

		virtual void	action( void ) const;

	public :

		RobotomyRequestForm( const std::string target );
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &rhs );
};

#endif
