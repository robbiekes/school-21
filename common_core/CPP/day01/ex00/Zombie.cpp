#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "'Zombie' constructor is called" << std::endl; }
Zombie::Zombie(std::string name) : name(name) {}
Zombie::~Zombie() { std::cout << "Destructor is called - " << name << " is dead." << std::endl; }

void Zombie::announce() { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
