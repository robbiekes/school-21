#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl a;
		a.complain(av[1]);
	}
	else
		std::cout << "Invalid number of arguments" << std::endl;
	return 0;
}