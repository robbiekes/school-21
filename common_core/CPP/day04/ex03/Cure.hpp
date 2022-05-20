#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	std::string name;

public:
	Cure();
	~Cure();
	Cure(const Cure &other);
	Cure& operator=(const Cure &other);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif