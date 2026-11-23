#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {

	public :

		Intern();
		~Intern();
		Intern( const Intern &src );
		Intern &operator=( const Intern &rhs );

		AForm	*makeForm( const std::string name, const std::string target ) const;
};

#endif
