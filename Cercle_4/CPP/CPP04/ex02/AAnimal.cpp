#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::~AAnimal() 
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal::AAnimal( AAnimal const &src )
{
	*this = src;

	return ;
}

AAnimal	&AAnimal::operator=( AAnimal const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}

const std::string	AAnimal::getType() const
{
	return _type;
}
