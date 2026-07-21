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

void	ScavTrap::takeDamage( unsigned int amount ) 
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

void	ScavTrap::beRepaired( unsigned int amount ) 
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

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl << std::endl;
}
