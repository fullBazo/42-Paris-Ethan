#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30) {

	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src)
{
	*this = src;

	return;
}

FragTrap &	FragTrap::operator=(const FragTrap &rhs)
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

void	FragTrap::attack( const std::string& target ) 
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

	std::cout << "FragTrap " << _name << " attacks " 
			  << target << ", causing " << _dmg 
			  << " point(s) of damage!" << std::endl;

	std::cout << "Mana points left : " << _mana << std::endl << std::endl;

}

void	FragTrap::takeDamage( unsigned int amount ) 
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

void	FragTrap::beRepaired( unsigned int amount ) 
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

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap is now high fiving himself." << std::endl << std::endl;
}
