#include "wrongAnimal.hpp"

wrongAnimal::wrongAnimal() : _type("wrongAnimal")
{
	std::cout << "wrongAnimal constructor called" << std::endl;
};

wrongAnimal::~wrongAnimal() 
{
	std::cout << "wrongAnimal destructor called" << std::endl;
};

wrongAnimal::wrongAnimal( wrongAnimal const &src )
{
	*this = src;

	return ;
}

wrongAnimal	&wrongAnimal::operator=( wrongAnimal const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}

const std::string	wrongAnimal::getType() const
{
	return _type;
}

void	wrongAnimal::makeSound() const
{
	std::cout << "*Fake Random Human animal sound*" << std::endl;
}