# include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.type;
	return *this;
	std::cout << "Cat assignment operator called" << std::endl;
}

void Cat::makeSound() const { std::cout << "meooow" << std::endl; }

const std::string& Cat::getType() const { return type; }