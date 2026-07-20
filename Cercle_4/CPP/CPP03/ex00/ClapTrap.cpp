#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _mana(10), _dmg(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	*this = src;

	return;
}

ClapTrap &	ClapTrap::operator=(const ClapTrap &rhs)
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

void	ClapTrap::attack( const std::string& target ) 
{
	if (_hp <= 0) 
		std::cout << _name << "can't attack while dead. Dumbass." << std::endl; 
	else if (_mana <= 0 )
		std::cout << _name << "can't attack with no mana." << std::endl; 
	_mana -= 1;
	std::cout << "ClapTrap " << _name << " attacks " 
			  << target << ", causing " << _dmg 
			  << " point(s) of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) 
{
	_hp -= amount;
	std::cout << 
}

void	ClapTrap::beRepaired( unsigned int amount ) {};