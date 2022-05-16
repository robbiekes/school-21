#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() { std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl; }
void Harl::info() { std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl; }
void Harl::warning() { std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;};
void Harl::error() { std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl; }

int getlevel(std::string level)
{
	std::string list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == list[i])
			return i;
	}
	return -1;
}

void Harl::complain(std::string level)
{
	int i = getlevel(level);
	switch (i)
		{
			case 0:
				debug();
				break;
			case 1:
				info();
				break;
			case 2:
				warning();
				break;
			case 3:
				error();
				break;
			default:
				std::cout << "kkkhhhhhhhshshshsshhhhh" << std::endl;
				break;
		}
}