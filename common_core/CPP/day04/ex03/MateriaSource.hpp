#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria* materias[4];
	
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource& operator=(const MateriaSource &other);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria *);
	virtual AMateria* createMateria(std::string const &type);
};

#endif