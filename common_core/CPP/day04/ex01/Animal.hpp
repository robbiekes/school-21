#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
	You should create a polymorphic class with a virtual destructor, because
	when you call delete on a variable of type Base*, the Base::~Base() method is called. 
	If it is virtual, then the call is dynamically dispatched to the final method (based on the dynamic type),
	in this case Derived::~Derived(), but if it is not, then Derived::~Derived() is never called, thus never executed.

	Besides, all heirs should have a virtual or protected destructor,
	otherwise deleting an instance via a pointer to a base class results in undefined behavior.
*/

class Animal
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual void makeSound() const;
	virtual const std::string& getType() const;
};

#endif