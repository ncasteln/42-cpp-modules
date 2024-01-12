/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:12:54 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 16:18:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact( void ) {
	this->isSet = false;
}

Contact::~Contact( void ) {}

t_contact Contact::getContact( void ) const {
	return (this->data_);
}

int Contact::getIsSet( void ) const {
	return (this->isSet);
}

void Contact::setField( std::string *field, int i ) {
	while (1) {
		std::cout << Contact::contactList[i] << ": ";
		getline(std::cin, *field);
		if (std::cin.fail()) {
			std::cerr << "Error: std::cin" <<std::endl;
			exit(1);
		}
		if (!(*field).empty())
			break ;
		std::cout << "[!!!] Empty fields are not allowed: retry [!!!]" << std::endl;
	}
}

void Contact::setContact( int i ) {
	Contact::setField(&this->data_.fname_, 0);
	Contact::setField(&this->data_.lname_, 1);
	Contact::setField(&this->data_.nname_, 2);
	Contact::setField(&this->data_.phone_, 3);
	Contact::setField(&this->data_.secret_, 4);
	this->data_.i_ = i;
	this->isSet = true;
}

/* DISPLAY METHODS */
std::string	Contact::contactList[5] = { "First name", "Last name", "Nickname", "Phone number", "Your darkest secret"};
std::string Contact::headerRow[4] = { "INDEX", "FIRST NAME", "LAST NAME", "NICKNAME" };
std::string Contact::emptyRow[4] = { "", "", "", "" };

void Contact::displayContact( void ) const {
	std::cout	<< std::endl
				<< "* Contact number [ " << this->data_.i_ << " ]" << std::endl
				<< std::setw(24) << std::left << "* First name: " << this->data_.fname_ << std::endl
				<< std::setw(24) << std::left << "* Last name: " << this->data_.lname_ << std::endl
				<< std::setw(24) << std::left << "* Nickname: " << this->data_.nname_ << std::endl
				<< std::setw(24) << std::left << "* Phone number: " << this->data_.phone_ << std::endl
				<< std::setw(24) << std::left << "* Your darkest secret: " << this->data_.secret_ << std::endl;
}

void Contact::displayRow( std::string s[4] ) {
	for (int i = 0; i < 4; i++) {
		if (s[i].length() > 10) {
			s[i] = s[i].substr(0, 10);
			*(s[i].rbegin()) = '.';
		}
		std::cout << "|" << std::setw(10) << std::right << s[i];
	}
	std::cout << "|" << std::endl;
}
