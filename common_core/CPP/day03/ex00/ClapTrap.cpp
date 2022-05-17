#include "ClapTrap.hpp"

// add operator<< and chech for hit and energy points before attacking

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {}
ClapTrap::~ClapTrap() {}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {}
ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	hitPoints -= attackDamage;
	energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " repairs itself and gets " << amount << " health points back!" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " was hit and loses " << amount << " points of health!" << std::endl;
	hitPoints -= amount;
}
