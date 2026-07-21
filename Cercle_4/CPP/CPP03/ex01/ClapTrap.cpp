#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _mana(10), _dmg(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}
ClapTrap::ClapTrap( std::string name, int hp, int mana, int dmg ) : _name(name), _hp(hp), _mana(mana), _dmg(dmg) 
{
	std::cout << "ClapTrap constructor parent called." << std::endl;	
};

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

	if (_hp <= 0) {
		std::cout << _name << " can't attack while dead. Dumbass." << std::endl << std::endl;
		return ;
	}

	else if ( _mana <= 0 ) {
		std::cout << _name << " can't attack with no mana." << std::endl << std::endl; 
		return ; 
	}

	_mana -= 1;

	std::cout << "ClapTrap " << _name << " attacks " 
			  << target << ", causing " << _dmg 
			  << " point(s) of damage!" << std::endl;

	std::cout << "Mana points left : " << _mana << std::endl << std::endl;

}

void	ClapTrap::takeDamage( unsigned int amount ) 
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

void	ClapTrap::beRepaired( unsigned int amount ) 
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