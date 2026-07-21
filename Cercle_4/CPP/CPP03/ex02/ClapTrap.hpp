#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

	protected :

		std::string _name;
		int			_hp;
		int 		_mana;
		int			_dmg;
		ClapTrap( std::string name, int hp, int mana, int dmg );

	public :

		ClapTrap( std::string name );
		~ClapTrap();
		ClapTrap( ClapTrap const & src );
		ClapTrap & operator=( ClapTrap const & rhs );

		void	attack(	const std::string& target );
		void	takeDamage(	unsigned int amount );
		void	beRepaired(	unsigned int amount );

};



#endif