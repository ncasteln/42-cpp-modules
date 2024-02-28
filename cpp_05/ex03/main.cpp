/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 09:05:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

///////////////////////////// simple /////////////////////////////////////////
int main ( void ) {
	Bureaucrat					b("John", 1);
	ShrubberyCreationForm		s;
	try {
		b.signForm(s);
		b.executeForm(s);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}

// int main ( void ) {
// 	Intern	i;
// 	AForm	*f;
// 	try {
// 		f = i.makeForm("presidential pardon", "Nico");
// 		std::cout << *f << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	if (f) delete f;
// 	return (0);
// }

// int main ( void ) {
// 	Intern		i;
// 	AForm*		f;
// 	try {
// 		f = i.makeForm("404", "Nico");
// 		if (f)
// 			std::cout << *f << std::endl;
// 		else
// 			std::cout << "f is [ NULL ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	if (f) delete f;
// 	return (0);
// }

// ///////////////////////// copy constructor and op= ////////////////////////
// int main ( void ) {
// 	Intern	i;
// 	AForm*	f;
// 	Intern	g( i );
// 	try {
// 		f = g.makeForm("{  X*(X(W*(*&#$*$(#$&)  }", "Nico");
// 		f = g.makeForm("robotomy request", "Nico");
// 		if (f)
// 			std::cout << *f << std::endl;
// 		else
// 			std::cout << "f is [ NULL ]" << std::endl;
// 		std::cout << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	if (f) delete f;
// 	return (0);
// }

///////////////////////////// mix /////////////////////////////////////////
// int main ( void ) {
// 	Bureaucrat	*s = new Bureaucrat("Threat", 12);
// 	Bureaucrat	*b = new Bureaucrat("Boss", 1);
// 	Intern		*h = new Intern();
// 	AForm		*p;
// 	AForm		*null = NULL;
// 	try {

// 		p = h->makeForm("robotomy request", "Boss");
// 		b->signForm(*p);
// 		s->executeForm(*p);
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	if (s) delete s;
// 	if (b) delete b;
// 	if (h) delete h;
// 	if (p) delete p;
// 	if (null) delete null;
// 	std::cout << std::endl;
// 	return (0);
// }
