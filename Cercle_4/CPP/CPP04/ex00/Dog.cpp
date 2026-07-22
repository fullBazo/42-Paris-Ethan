#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
}

Dog::~Dog(){};

Dog::Dog( Dog const &src ) : Animal(src)
{
	*this = src;

	return ;
}

Dog	&Dog::operator=( Dog const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}

const std::string	Dog::getType() const
{
	return _type;
}
void	Dog::makeSound() const
{
	std::cout << "Waouf Waouf je mange ma merde" << std::endl;
}