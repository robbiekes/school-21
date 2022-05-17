#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { std::cout << "ScavTrap constructor called" << std::endl; } // определить поля вручную, если не сработает

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "ScavTrap assignment constructor called" << std::endl;
	}
	return *this;
}

void ScavTrap::attack(std::string const target)
{
	if (!hitPoints)
		std::cout << "ScavTrap " << name << "is dead" << std::endl;
	if (!energyPoints)
		std::cout << "Cannot attack, not enough energy" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ScavTrap::guardGate() { std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl; }
