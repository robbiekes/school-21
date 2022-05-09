#include "Contact.hpp"

//Contact& Contact::operator=(const Contact &other)
//{
//	this->firstName = other.firstName;
//	this->
//}

void Contact::createContact(Contact &contact)
{
	std::string str;

	std::cout << "Enter first name: ";
	std::cin >> str;
	contact.setFirstName(str);

	std::cout << "Enter last name: ";
	std::cin >> str;
	contact.setLastName(str);

	std::cout << "Enter nickname: ";
	std::cin >> str;
	contact.setNickname(str);

	std::cout << "Enter dark secret: ";
	std::cin >> str;
	contact.setSecret(str);

	std::cout << "Enter number: ";
	std::cin >> str;
	contact.setNumber(str);
}