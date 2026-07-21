#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	std::cout << "=== Test ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << std::endl << "=== Test ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("Dummy");
	scav.attack("Dummy");
	scav.takeDamage(30);
	scav.beRepaired(10);

}