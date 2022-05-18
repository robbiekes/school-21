#include "FragTrap.hpp"

int main()
{
	FragTrap a("Frank");
	a.attack("a goblin");
	a.takeDamage(5);
	a.attack("a goblin");
	a.takeDamage(5);
	a.beRepaired(15);
	a.highFivesGuys();

	//ClapTrap *b = new ScavTrap("Eliot");
	//b->attack("a monster");
	//delete b;
}