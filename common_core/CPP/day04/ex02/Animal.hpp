#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
	Animal class doesn’t have implementation of makeSound(), but all animals must make some sound.
	
	1. A class is abstract if it has at least one pure virtual function.
	2. We cannot create objects of abstract classes.
	3. We can have pointers and references of abstract class type. 
	4. We must override that function in the derived class, otherwise the derived class will also become abstract class.
	5. A pure virtual function is declared by assigning 0 in declaration.
	6. An abstract class can have constructors. 
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
	virtual void makeSound() const = 0;
	virtual const std::string& getType() const = 0;
};

#endif