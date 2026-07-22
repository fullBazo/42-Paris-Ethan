#include "wrongCat.hpp"

wrongCat::wrongCat()
{
	_type = "wrongCat";

	std::cout << "wrongCat constructor called" << std::endl;
}

wrongCat::~wrongCat()
{
	std::cout << "wrongCat destructor called" << std::endl;

};

wrongCat::wrongCat( wrongCat const &src ) : wrongAnimal(src)
{
	*this = src;

	return ;
}

wrongCat	&wrongCat::operator=( wrongCat const &rhs )
{
	if ( this != &rhs )
		_type = rhs._type;

	return *this;
}


const std::string	wrongCat::getType() const
{
	return _type;
}
void	wrongCat::makeSound() const
{
	std::cout << "FAKE Miaou miaou frero" << std::endl;
}