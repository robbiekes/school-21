#include "AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria &other) {} // While assigning a Materia to another, copying the type doesn’t make sense.

AMateria& AMateria::operator=(const AMateria &other) { return *this; }

std::string const& AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) {std::cout << target.getName() << std::endl; }

