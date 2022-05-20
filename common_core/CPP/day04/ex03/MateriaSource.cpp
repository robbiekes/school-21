#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materias() {}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete materias[i];
		for (int i = 0; i < 4; i++)
			materias[i] = other.materias[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete materias[i];
		for (int i = 0; i < 4; i++)
			materias[i] = other.materias[i];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete materias[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == nullptr)
			materias[i] = materia->clone();
		return ;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return nullptr;
}