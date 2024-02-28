/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:40:27 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/19 08:41:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// ------------------------------------------------------ CANONICAL CONSTRUCTORS
RobotomyRequestForm::RobotomyRequestForm( void ) {
	std::cout << "[RobotomyRequestForm] default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	// std::cout << "[RobotomyRequestForm] destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& obj ):
	AForm(obj),
	_target(obj._target) {
	std::cout << "[RobotomyRequestForm] copy constructor" << std::endl;
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
RobotomyRequestForm::RobotomyRequestForm( const std::string target ):
	AForm("RRF", 72, 45),
	_target(target) {
	std::cout << "[RobotomyRequestForm] constructor" << std::endl;
}

int RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	this->AForm::isExecutable(executor);
	std::cout << "* VROOOOOM RUMBLE VROO-ROO-RRROOOM PURRRR TUCKTUCK clangKLANG clangKLANG RAT-A-TAT-TAT WHIRRRRRR *" << std::endl;
	std::srand(std::time(NULL));
	if ((std::rand() % 2) % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " has NOT been robotomized" << std::endl;
	return (0);
}
