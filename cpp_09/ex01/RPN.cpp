/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:44 by nico              #+#    #+#             */
/*   Updated: 2024/03/20 13:12:40 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ------------------------------------------------------------- CANONICAL FORM
RPN::RPN( void ) {};

RPN::~RPN( void ) {};

RPN::RPN( const RPN& ) {
	//implement
};

RPN& RPN::operator=( const RPN& rhs) {
	//implement
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
RPN::RPN( char* input ) {
	std::string s(input);
	if (s.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw InvalidInput();
	// trim whitespaces
	//  "8 9 * 9 - 9 - 9 - 4 - 1 +"
	std::string arg;
	while (s.find(" ") != std::string::npos) {
		arg = s.substr(0, s.find(" "));
		std::cout << "["  << arg<< "]" << std::endl;
		this->_data.push(arg);
		s.erase(0, s.find(" ") + 1);
	}
	arg = s.substr(0, s.find(" "));
	this->_data.push(arg);
	std::cout << "["  << arg<< "]" << std::endl;
};

// ----------------------------------------------------------------- EXCEPTIONS
const char* RPN::InvalidInput::what() const throw() {
	return ("invalid input");
}
