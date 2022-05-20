# include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() 
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

// we use "new" in copy constructor due to avoid pointing to the Other's memory
Cat::Cat(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		brain = new Brain(*other.brain);
		std::cout << "Cat copy constructor called" << std::endl;
	}
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Cat assignment operator called" << std::endl;
		type = other.type;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const { std::cout << "meooow" << std::endl; }

const std::string& Cat::getType() const { return type; }