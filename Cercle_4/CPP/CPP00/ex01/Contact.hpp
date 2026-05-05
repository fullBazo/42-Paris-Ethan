#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

	public :

		Contact();
		~Contact();

		void setFirstName(std::string const &name);
		std::string getFirstName() const;

		void setLastName(std::string const &lastname);
		std::string getLastName() const;

		void setNickname(std::string const &nickname);
		std::string getNickname() const;

		void setPhoneNumber(std::string const &number);
		std::string getPhoneNumber() const;

		void setDarkestSecret(std::string const &secret);
		std::string getDarkestSecret() const;
	
	private :

		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif