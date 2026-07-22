#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain { 

	private :
		std::string	ideas[100];

	public :
		Brain();
		~Brain();
		Brain( const Brain &src );
		Brain &operator=( const Brain &rhs );

		std::string	getIdeas(int index) const;
		void		setIdeas(int index, std::string idea);

};

#endif