#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;
	std::cout << "Welcome, User!\nPlease enter a command: " << std::endl;
	std::cout << "1. ADD\n2. SEARCH\n3. EXIT\n" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
			return 0;
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
	}
	
}