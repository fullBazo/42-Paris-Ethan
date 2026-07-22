#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
}

Cat::~Cat(){};

Cat::Cat( Cat const &src ) : Animal(src)
{
	*this = src;

	return ;
}

Cat	&Cat::operator=( Cat const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}


const std::string	Cat::getType() const
{
	return _type;
}
void	Cat::makeSound() const
{
	std::cout << "Miaou miaou frero" << std::endl;
}