#include "Ice.hpp"

AMateria* Ice::clone() const 
{
	return new Ice(*this);
}