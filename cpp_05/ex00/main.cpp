/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/16 12:01:01 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ( void ) {
	try {
		Bureaucrat	b("B", 1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Amsterdam", -190);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Zed", +9999);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Bonnie", 3);
		b.incrementGrade(); // 2
		b.incrementGrade(); // 1
		b.incrementGrade(); // XXX
		b.incrementGrade(); // XXX
		b.incrementGrade(); // XXX
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Clide", 149);
		b.decrementGrade(); // 150
		b.decrementGrade(); // XXX
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////

	try {
		Bureaucrat	b("Nico", 1);
		Bureaucrat	c("Johnny", 2);

		c = b;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << std::endl;

		Bureaucrat	d;
		d = b;
		std::cout << b << std::endl;
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
