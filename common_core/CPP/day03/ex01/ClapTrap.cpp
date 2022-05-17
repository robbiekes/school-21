#include "ClapTrap.hpp"

// add operator<< and chech for hit and energy points before attacking

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) { std::cout << "Default constructor is called" << std::endl; }
ClapTrap::~ClapTrap() { std::cout << "Destructor is called" << std::endl; }
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10) { std::cout << "Constructor is called" << std::endl; }
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
	if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		c
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
