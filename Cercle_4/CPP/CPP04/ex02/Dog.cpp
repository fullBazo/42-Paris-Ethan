#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	brain = new Brain();

	std::cout << "Dog constructor called." << std::endl;

}

Dog::~Dog()
{
	delete brain;

	std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog( Dog const &src ) : AAnimal(src), brain(new Brain(*src.brain))
{
}

Dog	&Dog::operator=( Dog const &rhs )
{
	if ( this != &rhs )
	{
		_type = rhs._type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}

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

Brain*	Dog::getBrain( void ) const
{
	return brain;
}