#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Frank");
	a.attack("a goblin");
	a.takeDamage(5);
	a.attack("a goblin");
	a.takeDamage(5);
	a.beRepaired(15);
	a.guardGate();

	//ClapTrap *b = new ScavTrap("Eliot");
	//b->attack("a monster");
	//delete b;
}