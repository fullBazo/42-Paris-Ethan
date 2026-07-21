#include "ClapTrap.hpp"

int main( void ) 
{ 
	ClapTrap mc("Subaru");

	mc.takeDamage(10);
	mc.attack("Edna");
	mc.attack("Edna");
}