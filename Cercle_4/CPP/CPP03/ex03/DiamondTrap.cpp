#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name", 100, 50, 30 ) , ScavTrap(name), FragTrap(name) {

	_name = name;
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;

	return;
}

DiamondTrap &	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if ( this != &rhs )
	{
		_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
		_hp = rhs._hp;
		_mana = rhs._mana;
		_dmg = rhs._dmg;
	}

	return *this;
}

void	DiamondTrap::takeDamage( unsigned int amount ) 
{
	if (_hp <= 0) {
		std::cout << _name << " is dead and can't take more damage." << std::endl << std::endl;
		return ;
	}

	_hp -= amount;

	std::cout << _name << " took " << amount << " point(s) of damage(s) !" << std::endl;

	std::cout << "HP left : " << _hp << std::endl;

	if (_hp <= 0) {
		std::cout << _name << " is now dead." << std::endl << std::endl;
		return ;
	}
	std::cout << std::endl;
}

void	DiamondTrap::beRepaired( unsigned int amount ) 
{

	if (_hp <= 0) {
		std::cout << _name << " can't be repaired while dead." << std::endl << std::endl;
		return ;
	}

	else if (_mana <= 0) {
		std::cout << _name << " can't be repaired with no mana left." << std::endl << std::endl;
		return ;
	}

	_mana -= 1;
	_hp += amount;

	std::cout << _name << " repaired himself and regained " << amount << " HP !" << std::endl;
	std::cout << "Mana points left : " << _mana << std::endl;
	std::cout << "HP left : " << _hp << std::endl << std::endl;

}

void	DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << _name << ", ClapTrap name : " << ClapTrap::_name << std::endl;
}
