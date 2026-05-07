#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() {
	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_ask_number(std::string const &prompt)
{
	std::string input;
	

	while (true) {

		std::cout << prompt;
		if (!(std::getline(std::cin, input)))
		{
			std::cout << "\nEOF detected, exiting program." << std::endl;
			return 0;
		}
		if (input.empty())
			continue;
		bool only_digit = true;
		for (size_t i = 0; i < input.length(); ++i) {
			if (!std::isdigit(input[i]) && !(std::isspace(input[i]))) {
				std::cout << "Only digits please" << std::endl;
				only_digit = false;
				break ;
			}
		}
		if (only_digit)
			return input;
	}
}

std::string PhoneBook::_ask(std::string const &prompt) {

	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!(std::getline(std::cin, input)))
			return "";
		if (input.empty())
			continue;
		bool only_spaces = true;
		for (size_t i = 0; i < input.length(); ++i) {
			if (!std::isspace(input[i])) {
				only_spaces = false;
				break;
			}
		}
		if (!only_spaces)
			return input;
	}
}

void	PhoneBook::add_contact() {

	std::string input;

	_contacts[_index].setFirstName(_ask("First name : "));
	if (std::cin.eof()) return ;
	/*-------------------------------------------------*/
	_contacts[_index].setLastName(_ask("Last name : "));
	if (std::cin.eof()) return ;
	/*-------------------------------------------------*/
	_contacts[_index].setNickname(_ask("Nickname : "));
	if (std::cin.eof()) return ;
	/*-------------------------------------------------*/
	_contacts[_index].setPhoneNumber(_ask_number("Phone number : "));
	if (std::cin.eof()) return ;
	/*-------------------------------------------------*/
	_contacts[_index].setDarkestSecret(_ask("Darkest Secret : "));
	if (std::cin.eof()) return ;
	/*-------------------------------------------------*/
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

std::string	PhoneBook::_truncate(std::string const &to_trunc) {

	std::string out;

	if (to_trunc.length() >= 10) {
		out = to_trunc.substr(0, 9) + ".";
	}
	else
		out = to_trunc;
	return out;
}

void PhoneBook::_display_contact(int c) {

	std::cout << "First Name : " << _contacts[c].getFirstName() << std::endl;
	std::cout << "Last Name : " << _contacts[c].getLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[c].getNickname() << std::endl;
	std::cout << "Phone Number : " << _contacts[c].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << _contacts[c].getDarkestSecret() << std::endl;
}

int	valid_index(std::string const &index) {

	if (index.empty()) {
		std::cout << "Need an input" << std::endl;
		return 0;
	}
	for (size_t i = 0; i < index.length(); ++i) {
		if (!std::isdigit(index[i]) && i >= 1) {
			std::cout << "Invalid input, try again !" << std::endl;
			return (0);
		}
		if (index[i] < '0' || index[i] > '7') {
			std::cout << "Index out of range, try again !" << std::endl;
			return(0);
		}
	}
	return (1);
}

void	PhoneBook::search_contact() {

	std::string input;
	int c;

	if (_count == 0) {
		std::cout << "Phonebook empty!" << std::endl;
		return;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;

	for (int i = 0; i < _count; ++i) {
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << _truncate(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << _truncate(_contacts[i].getNickname()) << "|" << std::endl;
	}
	while (true) {
		std::cout << "Index ? : ";
		if (!(std::getline(std::cin, input)))
			return;
		if (!valid_index(input))
			continue ;
		c = std::atoi(input.c_str());
		if (c < 0 || c > _count - 1) {
			std::cout << "Index out of range, try again !" << std::endl;
			continue ;
		}
		else {
			_display_contact(c);
			break ;
		}
	}
}
