#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define PHONEBOOK_SIZE 8

class PhoneBook
{
private:
	int 	size;
	Contact	contacts[PHONEBOOK_SIZE];

public:
	PhoneBook() {}
	~PhoneBook() {}

	void add();
	void search();
	void displayPhoneBook(int index);
	void searchByIndex();
};

#endif