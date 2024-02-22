/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 14:29:10 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
	***** EVALUATION *****
	• check Robotomy use of srand() and (TIME)
	• Intern operator= is done in a different way without justification, it can
	be done either so or like in the previous exercises

*/
// int main ( void ) {
// 	Intern	i;
// 	AForm	*f;
// 	try {
// 		f = i.makeForm("presidential pardon", "Nico");
// 		std::cout << *f << std::endl;
// 		delete f;
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	delete f;
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
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	delete f;
// 	return (0);
// }

// ///////////////////////// copy constructor and op= ////////////////////////
int main ( void ) {
	Intern	i;
	AForm*	f;
	Intern	g( i );
	try {
		f = g.makeForm("robotomy request", "Nico");
		if (f)
			std::cout << *f << std::endl;
		else
			std::cout << "f is [ NULL ]" << std::endl;
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete f;
	return (0);
}

// ///////////////////////////// mix /////////////////////////////////////////
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
// 		std::cout << e.what() << std::endl;
// 	}
// 	delete s;
// 	delete b;
// 	delete h;
// 	delete p;
// 	delete null;
// 	std::cout << std::endl;
// 	return (0);
// }
