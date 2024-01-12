/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:57:39 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 16:17:57 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {}

PhoneBook::~PhoneBook( void ) {}

void PhoneBook::getAllContact( void ) const {
	if (!this->c_[0].getIsSet()) {
		std::cout << "*** [Your contact list is empty!] ***" << std::endl;
		return ;
	}
	Contact::displayRow(Contact::headerRow);
	Contact::displayRow(Contact::emptyRow);
	for (int i = 0; i < 8; i++) {
		if (this->c_[i].getIsSet()) {
			std::string s[4] = {
				std::string(1, i + '0'),
				this->c_[i].getContact().fname_,
				this->c_[i].getContact().lname_,
				this->c_[i].getContact().nname_,
			};
			Contact::displayRow(s);
		}
	}
	this->getContactByIndex();
}

int PhoneBook::isValidZero(std::string line) {
	std::string::iterator	it;

	it = line.begin();
	while (*it && *it == '0')
		it++;
	if (it == line.end())
		return (1);
	return (0);
}

int PhoneBook::isValidIndex(std::string line, int n) {
	if (line.find("+-") != std::string::npos)
		return (0);
	if (n == 0 && !PhoneBook::isValidZero(line))
		return (0);
	if (n < 0 || n > 7)
		return (0);
	return (1);
}

void PhoneBook::getContactByIndex( void ) const {
	std::string	line;
	int			n;

	n = -1;
	while (1) {
		std::cout << std::endl << "* Choose a contact between [0] and [7]: ";
		getline(std::cin, line);
		if (std::cin.fail()) {
			std::cerr << "Error: std::cin" <<std::endl;
			exit(1);
		}
		n = std::atoi(line.c_str());
		if (!isValidIndex(line, n) || line.empty())
			std::cout << "[!!!] Invalid input [!!!]";
		else
			break ;
	}
	for (int i = 0; i < 8; i++) {
		if (i == n) {
			if (!this->c_[i].getIsSet())
				std::cout << "*** [The contact doesn't exist] ***" << std::endl;
			else
				this->c_[i].displayContact();
		}
	}
}

void PhoneBook::addContact( void ) {
	Contact new_c;

	new_c.setContact(this->i_);
	this->c_[this->i_] = new_c;
	this->i_ += 1;
	if (this->i_ == 8) {
		this->i_ = 0;
	}
	std::cout << "*** [Contact added successfully] ***" << std::endl;
}
