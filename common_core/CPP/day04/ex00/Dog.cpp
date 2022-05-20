# include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Dog copy constructor called" << std::endl;
	}
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const { std::cout << "woof! woof!" << std::endl; }

const std::string& Dog::getType() const { return type; }