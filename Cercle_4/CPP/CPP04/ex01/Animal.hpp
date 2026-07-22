#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string> 
# include "Brain.hpp"

class Animal {

	protected :
		std::string _type;
	public :
		Animal();
		virtual ~Animal();
		Animal( Animal const &src );
		Animal &operator=( Animal const &src );

		virtual const std::string	getType() const; 
		virtual void	makeSound() const;
};

#endif