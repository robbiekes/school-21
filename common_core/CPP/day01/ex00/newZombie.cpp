#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *dude = new Zombie(name);
	return (dude);
}
