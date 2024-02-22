/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:43:49 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:37 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ------------------------------------------------------ CANONICAL CONSTRUCTORS
PresidentialPardonForm::PresidentialPardonForm( void ) {
	std::cout << "[PresidentialPardonForm] default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	// std::cout << "[PresidentialPardonForm] destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& obj ):
	AForm(obj),
	_target(obj._target) {
	std::cout << "[PresidentialPardonForm] copy constructor" << std::endl;
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
PresidentialPardonForm::PresidentialPardonForm( const std::string target ):
	AForm("PPF", 25, 5),
	_target(target) {
	std::cout << "[PresidentialPardonForm] constructor" << std::endl;
}

// ------------------------------------------------------------------ INHERITED
int PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	this->AForm::isExecutable(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (0);
}
