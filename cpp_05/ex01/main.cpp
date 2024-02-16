/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/16 14:01:53 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void ) {
	try {
		Bureaucrat	b("Bonnie", 10);
		Form		f_ok("f_50", 50, 50);
		Form		f_catch("f_1", 1, 1);

		b.signForm(f_ok);
		b.signForm(f_ok);	// already signed
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Bonnie", 10);
		Form		f_catch("f_1", 1, 1);

		b.signForm(f_catch); // no permissions
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Bonnie", -10); // too high
		Form		f_catch("f_1", 1, 1);

		b.signForm(f_catch); // no permissions
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}

	///////////////////////////////////////////////////////////////////////////

	try {
		Form		f_ok("f", 1, 2);
		Form		f_high("f", -25,-25); // too high grade requested
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}

	///////////////////////////////////////////////////////////////////////////

	try {
		Form		f("f", 9999, 9999); // too low grade requested
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}

	return (0);
}
