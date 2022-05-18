#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) 
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "FragTrap copy constructor called" << std::endl;
	}
} // определить поля вручную, если не сработает

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "FragTrap assignment constructor called" << std::endl;
	}
	return *this;
}

void FragTrap::attack(std::string const target)
{
	if (!hitPoints)
		std::cout << "FragTrap " << name << "is dead" << std::endl;
	if (!energyPoints)
		std::cout << "Cannot attack, not enough energy" << std::endl;
	else
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void FragTrap::highFivesGuys() { std::cout << "Hey, guys! High five! " << std::endl; }
