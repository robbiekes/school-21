#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon a("pistol");

	HumanA bob("Bob", a);
	bob.attack();
	a.setType("knife");
	bob.attack();

	Weapon b("katana");

	HumanB jim("Jim");
	jim.setWeapon(b);
	jim.attack();
	b.setType("bazuka");
	jim.attack();

	return 0;
}