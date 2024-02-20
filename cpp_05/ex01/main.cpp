/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 08:02:21 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void ) {
	/////////////////////// try ass operator= /////////////////////////////////
	// try {
	// 	Bureaucrat	b("Bonnie", 1);
	// 	Form		f("Basic", 5, 5);
	// 	Form		g;

	// 	b.signForm(f);

	// 	g = f;

	// 	std::cout << f << std::endl;
	// 	std::cout << g << std::endl;
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() <<  std::endl;
	// }
	// std::cout << std::endl;

	/////////////////////// already signed ////////////////////////////////////
	try {
		Bureaucrat	b("Bonnie", 10);
		Form		f_ok("f_50", 50, 50);
		Form		f_catch("f_1", 1, 1);

		b.signForm(f_ok);
		b.signForm(f_ok);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	/////////////////////// no permissions ////////////////////////////////////
	try {
		Bureaucrat	b("Bonnie", 10);
		Form		f_catch("f_1", 1, 1);

		b.signForm(f_catch); // no permissions
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	////////////////////// Bureaucrat high grade //////////////////////////////
	try {
		Bureaucrat	b("Bonnie", -10);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	////////////////////// Bureaucrat high grade //////////////////////////////
	try {
		Bureaucrat	b("Bonnie", 10);
		Form		f_catch("f_1", 1, 1);

		std::cout << b << std::endl;
		b.signForm(f_catch);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	//////////////////////// form high grade //////////////////////////////////
	try {
		Bureaucrat	b("Boss", 1);
		Form		f_ok("f_ok", 1, 2);
		std::cout << f_ok << std::endl;

		b.signForm(f_ok);
		std::cout << f_ok << std::endl;

		Form		f_high("f_high", -25,-25);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	///////////////////////// too low grade ///////////////////////////////////
	try {
		Form		f("f", 9999, 9999);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<  std::endl;
	}
	std::cout << std::endl;

	return (0);
}
