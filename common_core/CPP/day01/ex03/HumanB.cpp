#include "HumanB.hpp"

HumanB::HumanB() : name(""), weapon(0) {}
HumanB::~HumanB() {}
HumanB::HumanB(std::string name) : name(name) {}

void HumanB::attack() { std::cout << name << " attacks with their " << weapon->getType() << std::endl; }
void HumanB::setWeapon(Weapon &_weapon) { weapon = &_weapon; }