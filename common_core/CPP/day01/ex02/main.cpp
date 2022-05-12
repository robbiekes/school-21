#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	std::cout << "memory address of variable: " << &brain << std::endl;
	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "value of the string: " << brain << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}