#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon *weapon;

public:
	HumanB();
	~HumanB();
	HumanB(std::string  name);

	void setWeapon(Weapon &_weapon);
	void attack();
};

#endif