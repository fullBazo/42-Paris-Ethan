#include "Zombie.hpp"

int	main( void ){
	Zombie *z;
	std::string name = "coucou";
	std::string name2 = "salut";

	z = newZombie(name2);

	z->announce();
	delete z;
}


