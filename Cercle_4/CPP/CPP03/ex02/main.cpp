#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	std::cout << "=== Test FragTrap ===" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("Dummy");
	frag.takeDamage(40);
	frag.beRepaired(10);
	frag.highFivesGuys();

	std::cout << std::endl << "=== Test mana a 0 ===" << std::endl;
	for (int i = 0; i < 100; i++)
		frag.attack("Dummy");

	std::cout << std::endl << "=== Test mort ===" << std::endl;
	frag.takeDamage(1000);
	frag.attack("Dummy");
	frag.beRepaired(5);
	frag.takeDamage(1);
	frag.highFivesGuys();

	std::cout << std::endl << "=== Test copy constructor (vivant) ===" << std::endl;
	FragTrap original("Original");
	original.takeDamage(20);
	FragTrap copy(original);
	copy.attack("CopyTarget");
	copy.highFivesGuys();

	std::cout << std::endl << "=== Test operator= ===" << std::endl;
	FragTrap other("Other");
	other = original;
	other.attack("Target");

	return (0);
}