#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public :
		Dog();
		~Dog();
		Dog( Dog const &src );
		Dog &operator=( Dog const &src );

		virtual const std::string	getType() const;
		virtual void		makeSound() const;

};

#endif