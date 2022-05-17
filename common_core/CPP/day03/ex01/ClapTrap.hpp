#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream> 

/*
	1. now attributes of basic class ClapTrap are protected in order to let ScavTrap to use them
	
	2. Virtual keyword for destructor is necessary when you want different destructors should follow proper order
		while objects is being deleted through base class pointer. If your base class destructor is virtual then
		objects will be destructed in a order(firstly derived object then base). If your base class destructor is NOT virtual then
		only base class object will get deleted(because pointer is of base class "Base *myObj"). So there will be memory leak for derived object.
*/

class ClapTrap
{
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(ClapTrap const &other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, ClapTrap const &other);

#endif