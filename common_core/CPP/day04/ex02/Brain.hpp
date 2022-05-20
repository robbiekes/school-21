#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
protected:
	std::string array[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &other);
};

#endif
