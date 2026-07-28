#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"


class Dog : public AAnimal {

	private : 
		Brain* brain;

	public :
		Dog();
		~Dog();
		Dog( Dog const &src );
		Dog &operator=( Dog const &src );

		Brain*				getBrain( void ) const;
		virtual const std::string	getType() const;
		virtual void				makeSound() const;

};

#endif