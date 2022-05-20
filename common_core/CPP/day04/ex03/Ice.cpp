#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : name("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &other)
{
	if (this != &other)
		name = other.name;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
		name = other.name;
	return *this;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << name << " *" << std::endl; }
