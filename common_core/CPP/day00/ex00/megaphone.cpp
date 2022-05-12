#include <iostream>
#include <cctype>

void to_uppercase(std::string msg, int ac, int i)
{
	transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
	std::cout << msg;
	if (i != ac)
		std::cout << " ";
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
			to_uppercase(av[i], ac - 1, i);
		std::cout << std::endl;
	}
	return 0;
}