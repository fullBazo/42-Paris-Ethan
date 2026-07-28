#include "AMateria.hpp"


AMateria::AMateria( std::string const & type ) : _type(type)
{
}

~AMateria();
AMateria( const AMateria &src );
AMateria &operator=( const AMateria &rhs );

std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use( ICharacter& target );
