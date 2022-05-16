#include "Zombie.hpp"

int main()
{
	randomChump("Mary");
	
	Zombie dude1("Johnny");
	dude1.announce();

	Zombie *dude2 = newZombie("Max");
	dude2->announce();

	// delete dude2;
	return 0;
}