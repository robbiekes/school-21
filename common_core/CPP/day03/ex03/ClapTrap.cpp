#include "ClapTrap.hpp"

// add operator<< and chech for hit and energy points before attacking

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) { std::cout << "ClapTrap default constructor is called" << std::endl; }
ClapTrap::~ClapTrap() { std::cout << "Destructor is called" << std::endl; }
ClapTrap::ClapTrap(ClapTrap const &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10) { std::cout << "ClapTrap constructor is called" << std::endl; }
ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hitPoints)
		std::cout << "ClapTrap " << name << "is dead" << std::endl;
	if (!energyPoints)
		std::cout << "Cannot attack, not enough energy" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself and gets " << amount << " health points back!" << std::endl;
		hitPoints += amount;
		energyPoints--;
	}
	else
		std::cout << "Not enough energy points" << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " was hit and loses " << amount << " points of health!" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
}
