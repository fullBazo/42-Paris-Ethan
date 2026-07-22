#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "wrongAnimal.hpp"

class wrongCat : public wrongAnimal {

	public :
		wrongCat();
		~wrongCat();
		wrongCat( wrongCat const &src );
		wrongCat &operator=( wrongCat const &src );

		const std::string	getType() const;
		void		makeSound() const;

};


#endif