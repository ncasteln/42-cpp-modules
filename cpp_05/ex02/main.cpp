/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 08:06:18 by ncasteln         ###   ########.fr       */
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
		// Bureaucrat				b("Bonnie", 1);
		// ShrubberyCreationForm	f0("Home");

		// b.signForm(f0);
		// std::cout << f0 << std::endl << std::endl;

		// ShrubberyCreationForm	f1( f0 );
		// std::cout << f1 << std::endl << std::endl;

		// ShrubberyCreationForm	f2("_hell_");
		// f2 = f1;
		// std::cout << f2 << std::endl << std::endl;

		///////////////////////// ShrubberyCreationForm ///////////////////////
		Bureaucrat				b("Bonnie", 145);
		Bureaucrat				c("Clide", 137);
		ShrubberyCreationForm	s("Home");

		b.signForm(s);
		c.executeForm(s);

		///////////////////////// Shrubbery not signed ////////////////////////
		// Bureaucrat				c("Clide", 137);
		// ShrubberyCreationForm	s("Home");

		// c.executeForm(s);

		///////////////////////// Shrubbery not signed ////////////////////////
		// Bureaucrat				c("Clide", 137);
		// ShrubberyCreationForm	s("Home");

		// c.executeForm(s);

		///////////////////////// Grade too low for Shrubbery /////////////////
		// Bureaucrat				c("Clide", 145);
		// ShrubberyCreationForm	s("Home");

		// c.signForm(s);
		// c.executeForm(s);

		///////////////////////// Grade too low for Shrubbery /////////////////
		// Bureaucrat				c("Clide", 1);
		// ShrubberyCreationForm	s("Home");

		// c.signForm(s);
		// c.executeForm(s);

		///////////////////////// Robotomy ////////////////////////////////////
		// Bureaucrat				c("Clide", 1);
		// RobotomyRequestForm		f("Nico");

		// c.signForm(f);
		// c.executeForm(f);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
