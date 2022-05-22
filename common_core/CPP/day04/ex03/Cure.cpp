#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &other)
{
	if (this != &other)
		type = other.type;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
