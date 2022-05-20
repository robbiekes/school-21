#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		array[i] = "some idea";
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; };

Brain::Brain(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			array[i] = other.array[i];
		std::cout << "Brain constructor called" << std::endl;
	}
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		std::cout << "Brain assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++)
			array[i] = other.array[i];
	}
	return *this;
}
