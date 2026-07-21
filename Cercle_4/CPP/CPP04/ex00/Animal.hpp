#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string> 

class Animal {

	protected :
		std::string _type;
	public :
		Animal();
		~Animal();
		Animal( Animal const &src );
		Animal &operator=( Animal const &src );

		void	makeSound();
}

#endif