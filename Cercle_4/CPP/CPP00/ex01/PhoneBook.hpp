/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:17:26 by ehuet             #+#    #+#             */
/*   Updated: 2026/04/25 08:54:16 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	
	public :

		PhoneBook();
		~PhoneBook();

		void add_contact();
		void search_contact();
	private :
	
		Contact _contacts[8];
		int		_index;
		int		_count;

		std::string _ask(std::string const &prompt);
		std::string _truncate(std::string const &to_trunc);
		std::string _ask_number(std::string const &prompt);
		void _display_contact(int index);
};

#endif
