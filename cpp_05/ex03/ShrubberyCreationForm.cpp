/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:40:27 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/19 15:01:31 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ------------------------------------------------------ CANONICAL CONSTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm( void ) {
	std::cout << "[ShrubberyCreationForm] default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	// std::cout << "[ShrubberyCreationForm] destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& obj ):
	AForm(obj),
	_target(obj._target) {
	std::cout << "[ShrubberyCreationForm] copy constructor" << std::endl;
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ):
	AForm("SCF", 145, 137),
	_target(target) {
	std::cout << "[ShrubberyCreationForm] constructor" << std::endl;
}

int ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
	std::ofstream	fsout;

	this->AForm::isExecutable(executor);
	fsout.open((this->_target + "_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
	if (fsout.fail())
		return (1);
	fsout << "              * *" << std::endl;
	fsout << "           *    *  *" << std::endl;
	fsout << "      *  *    *     *  *" << std::endl;
	fsout << "     *     *    *  *    *" << std::endl;
	fsout << " * *   *    *    *    *   *" << std::endl;
	fsout << " *     *  *    * * .#  *   *" << std::endl;
	fsout << " *   *     * #.  .# *   *" << std::endl;
	fsout << "  *     '#.  #: #' * *    *" << std::endl;
	fsout << " *   * * '#. ##'       *" << std::endl;
	fsout << "   *       '###'" << std::endl;
	fsout << "             '##" << std::endl;
	fsout << "              ##." << std::endl;
	fsout << "              .##:" << std::endl;
	fsout << "              :###" << std::endl;
	fsout << "              ;###" << std::endl;
	fsout << "            ,####." << std::endl;
	fsout << "...........######............." << std::endl;
	fsout.close();
	return (0);
}
