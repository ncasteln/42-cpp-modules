/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:11:00 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/04 11:31:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>	//std::rand/srand()
#include <ctime>	//std::time()
#include <iostream>

/*	SUBJECT:
	It randomly instanciates A, B or C and returns the instance as a Base
	pointer. Feel free to use anything you like for the random choice
	implementation. */
static Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int r = std::rand() % 3;
	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	else
		return (new C);
}

/*	SUBJECT about this function:
	It prints the actual type of the object pointed to by p: "A", "B" or "C".

	The function try to perform Base-to-derived conversion. This is possible
	*/
static void identify(Base* p) {
	std::cout << "[ Identify using Base pointer ]" << std::endl;
	std::cout <<  "The instance generated was of type ";
	if (dynamic_cast<A*>(p))
		std::cout << "[ A ]" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "[ B ]" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "[ C ]" << std::endl;
}

/*	SUBJECT about this function:
	It prints the actual type of the object pointed to by p: "A", "B" or "C".
	Using a pointer inside this function is forbidden. */
static void identify(Base& p) {
	std::cout << "[ Identify using Base reference ]" << std::endl;
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "The instance generated was of type [ A ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "A: " << e.what() << std::endl;
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "The instance generated was of type [ B ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "B: "<< e.what() << std::endl;
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "The instance generated was of type [ C ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "C: " << e.what() << std::endl;
	}
}

/*	Identify() are just two ways to get the right type of the derived instance.
	While with identify(Base*) is possible to verify if NULL is returned from
	dynamic_cast, using identify(Base&) we have to catch the exception thrown in
	case of failure, which is std::bad_cast. */
int main ( void ) {
	Base*	p = generate();
	identify(p);

	std::cout << std::endl;

	identify(*p);

	delete p;
	return (0);
}
