#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private :
		std::string _name;

	public : 
		DiamondTrap( std::string name );
		~DiamondTrap();
		DiamondTrap( DiamondTrap const & src );
		DiamondTrap & operator=( DiamondTrap const &rhs );

		using	ScavTrap::attack;
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		void 	whoAmI();
};

#endif