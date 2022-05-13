#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string arg1(av[1]);
		std::string arg2(av[2]);
		std::string arg3(av[3]);
		Replace replace(arg1, arg2, arg3);
		replace.rewrite();
		return 0;
	}
	std::cout << "Invalid number of arguments" << std::endl;
	return 1;
}