#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : name("Cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &other)
{
	if (this != &other)
		name = other.name;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
		name = other.name;
	return *this;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) { std::cout << "* heals " << name << "'s wounds *" << std::endl; }
