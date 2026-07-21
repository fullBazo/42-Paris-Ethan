#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {

	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src)
{
	*this = src;

	return;
}

ScavTrap &	ScavTrap::operator=(const ScavTrap &rhs)
{
	if ( this != &rhs )
	{
		_name = rhs._name;
		_hp = rhs._hp;
		_mana = rhs._mana;
		_dmg = rhs._dmg;
	}

	return *this;
}

void	ScavTrap::attack( const std::string& target ) 
{

	if (_hp <= 0) {
		std::cout << _name << " can't attack while dead. Dumbass." << std::endl << std::endl;
		return ;
	}

	else if ( _mana <= 0 ) {
		std::cout << _name << " can't attack with no mana." << std::endl << std::endl; 
		return ; 
	}

	_mana -= 1;

	std::cout << "ScavTrap " << _name << " attacks " 
			  << target << ", causing " << _dmg 
			  << " point(s) of damage!" << std::endl;

	std::cout << "Mana points left : " << _mana << std::endl << std::endl;

}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl << std::endl;
}
