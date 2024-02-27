/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:07:30 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/27 17:01:56 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Intern::Intern( void ) {
	std::cout << "[Intern] default constructor" << std::endl;
}

Intern::~Intern( void ) {
	// std::cout << "[Intern] destructor" << std::endl; // removed for readability
}

/*
	Since there is nothing to copy, the idea was to call the default constructor
	but it is a c++11 standard. It is left empty.
*/
Intern::Intern( const Intern& obj ) {
	std::cout << "[Intern] copy constructor !!! makes nothing !!! " << std::endl;
	(void)obj;
}

/*
	Intern operator= simply return the left side without copying anything since
	there is nothing to copy. It is possible also to make it not-usable as the
	other classes in this module.
*/
Intern& Intern::operator=( const Intern& rhs ) {
	std::cout << "[Intern] assignment operator" << std::endl;
	(void)rhs;
	return (*this);
}

// --------------------------------------------------------------------- OTHERS
AForm *Intern::makeForm( std::string name, std::string target ) {
	std::cout << "Intern tries to create a form: " << std::endl;
	const std::string _formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i = 0;
	while (i < 3 && name != _formTypes[i])
		i++;
	switch (i) {
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "Form named " << name << " doesn't exist" << std::endl;
	}
	return (NULL);
}
