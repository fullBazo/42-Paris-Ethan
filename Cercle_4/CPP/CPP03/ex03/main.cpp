#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	std::cout << "=== Test DiamondTrap : construction ===" << std::endl;
	DiamondTrap diamond("Diamondy");

	std::cout << std::endl << "=== Test attack (doit venir de ScavTrap) ===" << std::endl;
	diamond.attack("Dummy");

	std::cout << std::endl << "=== Test takeDamage / beRepaired ===" << std::endl;
	diamond.takeDamage(50);
	diamond.beRepaired(10);

	std::cout << std::endl << "=== Test highFivesGuys (herite de FragTrap) ===" << std::endl;
	diamond.highFivesGuys();

	std::cout << std::endl << "=== Test whoAmI (nom clap vs nom normal) ===" << std::endl;
	diamond.whoAmI();

	std::cout << std::endl << "=== Test mana a 0 ===" << std::endl;
	for (int i = 0; i < 55; i++)
		diamond.attack("Dummy");

	std::cout << std::endl << "=== Test mort ===" << std::endl;
	diamond.takeDamage(1000);
	diamond.attack("Dummy");
	diamond.beRepaired(5);

	std::cout << std::endl << "=== Test copy constructor ===" << std::endl;
	DiamondTrap original("Original");
	DiamondTrap copy(original);
	copy.whoAmI();

	std::cout << std::endl << "=== Test operator= ===" << std::endl;
	DiamondTrap other("Other");
	other = original;
	other.whoAmI();

	std::cout << std::endl << "=== Fin (destruction en cascade) ===" << std::endl;
	return (0);
}