#include "PhoneBook.hpp"

void PhoneBook::displayPhoneBook()
{
	std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	std::cout << "|   Index   |First name | Last name |  Nickname |" << std::endl;
	std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	
}

void PhoneBook::search()
{
	PhoneBook::displayPhoneBook();
}

void PhoneBook::add()
{
	std::cout << "\nNew contact creating...\n" << std::endl;
	Contact::createContact(contacts[size++ % PHONEBOOK_SIZE]);
	std::cout << "\nNew contact created!\n" << std::endl;
}
