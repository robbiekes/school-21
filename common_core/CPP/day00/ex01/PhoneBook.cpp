#include "PhoneBook.hpp"

void displayHeader()
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  Index   |First name| Last name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::searchByIndex()
{
	int index;
	std::cout << "Enter index of a contact: ";
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > size)
	{
		std::cout << "Invalid argument" << std::endl;
		std::cin.clear();
	}
	else
	{
		displayHeader();
		displayPhoneBook(index - 1);
	}
}

void PhoneBook::displayPhoneBook(int index)
{
	std::wstring tmp;
	
	std::string firstName = this->contacts[index].getFirstName();
	std::string lastName = this->contacts[index].getLastName();
	std::string nickname = this->contacts[index].getNickname();

	std::cout << "|" << std::setw(10) << index + 1 << "|";
	if (firstName.length() >= 10)
		std::cout << firstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << firstName << "|";
	if (lastName.length() >= 10)
		std::cout << lastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << lastName << "|";
		
	if (nickname.length() >= 10)
		std::cout << nickname.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << nickname << "|";
	std::cout << "\n";
}

void PhoneBook::search()
{
	displayHeader();
	for (int i = 0; i < std::min(size, PHONEBOOK_SIZE); i++)
		displayPhoneBook(i);
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	searchByIndex();
}

void PhoneBook::add()
{
	std::cout << "\nNew contact creating...\n" << std::endl;
	Contact::createContact(contacts[size++ % PHONEBOOK_SIZE]);
	std::cout << "\nNew contact created!\n" << std::endl;
}
