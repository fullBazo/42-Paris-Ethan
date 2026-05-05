#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

/*-----------------------------------------------------------*/

void Contact::setFirstName(std::string const &name) {
	_firstName = name;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

/*-----------------------------------------------------------*/

void Contact::setLastName(std::string const &lastname) {
	_lastName = lastname;
}

std::string Contact::getLastName() const {
    return _lastName;
}

/*-----------------------------------------------------------*/

void Contact::setNickname(std::string const &nickname) {
	_nickname = nickname;
}

std::string Contact::getNickname() const {
    return _nickname;
}

/*-----------------------------------------------------------*/

void Contact::setPhoneNumber(std::string const &number) {
	_phoneNumber = number;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

/*-----------------------------------------------------------*/

void Contact::setDarkestSecret(std::string const &secret) {
	_darkestSecret = secret;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

