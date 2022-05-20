#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	Brain *brain;

public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual void makeSound() const;
	virtual const std::string& getType() const;
};

#endif