#include "Contact.hpp"

void Contact::createContact(Contact &contact)
{
	std::string str;

	std::cout << "Enter first name: ";
	getline(std::cin, str);
	contact.setFirstName(str);

	std::cout << "Enter last name: ";
	getline(std::cin, str);
	contact.setLastName(str);

	std::cout << "Enter nickname: ";
	getline(std::cin, str);
	contact.setNickname(str);

	std::cout << "Enter dark secret: ";
	getline(std::cin, str);
	contact.setSecret(str);

	std::cout << "Enter number: ";
	getline(std::cin, str);
	contact.setNumber(str);
}
