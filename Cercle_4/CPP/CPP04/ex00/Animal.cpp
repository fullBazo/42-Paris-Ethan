#include "Animal.hpp"

Animal::Animal() : _type("Animal"){};

Animal::~Animal() {};

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

void	Animal::makeSound()
{
	
}