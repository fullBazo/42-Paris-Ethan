#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string> 

class wrongAnimal {

	protected :
		std::string _type;
	public :
		wrongAnimal();
		~wrongAnimal();
		wrongAnimal( wrongAnimal const &src );
		wrongAnimal &operator=( wrongAnimal const &src );

		const std::string	getType() const; 
		void	makeSound() const;
};

#endif