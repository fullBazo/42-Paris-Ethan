#include "Cat.hpp"


Cat::Cat()
{
	_type = "Cat";
	brain = new Brain();

	std::cout << "Cat constructor called." << std::endl;

}

Cat::~Cat()
{
	delete brain;

	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat( Cat const &src ) : AAnimal(src), brain(new Brain(*src.brain))
{
}

Cat	&Cat::operator=( Cat const &rhs )
{
	if ( this != &rhs )
	{
		_type = rhs._type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}

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

Brain*	Cat::getBrain( void ) const
{
	return brain;
}