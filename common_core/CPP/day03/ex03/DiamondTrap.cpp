#include "DiamondTrap.hpp"

// Theory of basic class subobjects - https://stackoverflow.com/questions/69738775/what-is-a-base-class-subobject;

DiamondTrap::DiamondTrap()
{
	ClapTrap::name = "default_clap_name";
	this->name = "default";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor is called" << std::endl; }

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "DiamondTrap copy constructor called" << std::endl;
	}
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "DiamondTrap assignment constructor called" << std::endl;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << "\nClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(std::string const target)
{
	ScavTrap::attack(target);
}