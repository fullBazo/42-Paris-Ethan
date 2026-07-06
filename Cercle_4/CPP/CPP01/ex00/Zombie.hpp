#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	void announce( void );
	Zombie( std::string name );
	~Zombie();
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

