#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal() 
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal( Animal const &src )
{
	*this = src;

	return ;
}

Animal	&Animal::operator=( Animal const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}

const std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "*Random Animal sound*" << std::endl;
}