#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default") {}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria &other) 
{ 
	if (this != &other)
		type = other.type;
	return *this;
}

std::string const& AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) {std::cout << target.getName() << std::endl; }

