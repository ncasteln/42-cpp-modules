/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 09:03:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void ) {
	try {
		///////////////////////// Shrubbery copy constr/op== //////////////////
		ShrubberyCreationForm	f0("Home");
		ShrubberyCreationForm	f1( f0 );

		std::cout << f0 << std::endl << std::endl;
		std::cout << f1 << std::endl << std::endl;

		// ShrubberyCreationForm	f2("_hell_");
		// f2 = f1;	// not-usable
		// std::cout << f2 << std::endl << std::endl;

		///////////////////////// ShrubberyCreationForm ///////////////////////
		// Bureaucrat				b("Bonnie", 145);
		// Bureaucrat				c("Clide", 137);
		// ShrubberyCreationForm	s("Home");

		// b.signForm(s);
		// c.executeForm(s);

		///////////////////////// Shrubbery not signed ////////////////////////
		// Bureaucrat				c("Clide", 137);
		// ShrubberyCreationForm	s("Home");

		// c.executeForm(s);

		///////////////////////// Shrubbery not signed ////////////////////////
		// Bureaucrat				c("Clide", 137);
		// ShrubberyCreationForm	s("Home");

		// c.executeForm(s);

		/////////////////////// Grade too low for Shrubbery /////////////////
		// Bureaucrat				c("Clide", 145);
		// ShrubberyCreationForm	s("Home");

		// c.signForm(s);
		// c.executeForm(s);

		/////////////////////// Grade too low for Shrubbery /////////////////
		// Bureaucrat				c("Clide", 1);
		// ShrubberyCreationForm	s("Home");

		// c.signForm(s);
		// c.executeForm(s);

		/////////////////////// Robotomy ////////////////////////////////////
		// Bureaucrat				c("Clide", 1);
		// RobotomyRequestForm		f("Nico");

		// c.signForm(f);
		// c.executeForm(f);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
