#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain( Brain const &src )
{
	*this = src;

	return ;
}

Brain	&Brain::operator=( Brain const &rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 100; i++ )
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

void	Brain::setIdeas( int index, std::string idea )
{
	ideas[index] = idea;
}

std::string	Brain::getIdeas( int index ) const
{
	return ideas[index];
}