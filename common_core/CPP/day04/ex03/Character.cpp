#include "Character.hpp"

Character::Character() : name(""), slots() {}

Character::~Character() 
{
	for (int i = 0; i < 4; i++)
		delete slots[i];
}

Character::Character(const std::string name) : name(name), slots() {}

Character::Character(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete slots[i];
		for (int i = 0; i < 4; i++)
			slots[i] = other.slots[i]->clone();
	}
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete slots[i];
		for (int i = 0; i < 4; i++)
			slots[i] = other.slots[i]->clone();
	}
	return *this;
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (i < 4 && slots[i] == nullptr)
			slots[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 4 && slots[idx])
	{
		delete slots[idx];
		slots[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && slots[idx])
		slots[idx]->use(target);
}