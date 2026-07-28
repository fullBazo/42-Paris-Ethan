#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string> 
# include "Brain.hpp"

class AAnimal {

	protected :
		std::string _type;
	public :
		AAnimal();
		virtual ~AAnimal();
		AAnimal( AAnimal const &src );
		AAnimal &operator=( AAnimal const &src );

		virtual const std::string	getType() const; 
		virtual void	makeSound() const = 0;
};

#endif