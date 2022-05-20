#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character
{
	std::string name;
	AMateria *slots[4];

public:
	Character();
	Character(const std::string name);
	Character(const Character &other);
	Character& operator=(const Character &other);
	virtual ~Character() {}
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif