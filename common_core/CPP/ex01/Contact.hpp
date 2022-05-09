#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	Contact() : firstName(""), lastName(""), nickname(""), secret(""), number("") {}

	//Contact & operator=(const Contact &);
	static void createContact(Contact &contact);
	void setFirstName(std::string firstName) { this->firstName = firstName; } // since firstName is private we have to use a setter
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setNickname(std::string nickname) { this->nickname = nickname; }
	void setSecret(std::string secret) { this->secret = secret; }
	void setNumber(std::string number) { this->number = number; }
	~Contact() {}

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	secret;
	std::string number;
};

#endif