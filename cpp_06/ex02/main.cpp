/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 15:57:49 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

/*	SUBJECT
	It randomly instanciates A, B or C and returns the instance as a Base
	pointer. Feel free to use anything you like for the random choice
	implementation.
*/
static Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int r = std::rand() % 3;
	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	if (r == 2)
		return (new C);
}

/*	SUBJECT
	It prints the actual type of the object pointed to by p: "A", "B" or "C".
*/
static void identify(Base* p) {
	std::cout << "[ Identify using Base pointer ]" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "[ A ]" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "[ B ]" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "[ C ]" << std::endl;
}

/*	SUBJECT
	It prints the actual type of the object pointed to by p: "A", "B" or "C".
	Using a pointer inside this function is forbidden.
*/
static void identify(Base& p) {
	std::cout << "[ Identify using Base reference ]" << std::endl;
	try {
		dynamic_cast<A&>(p);
		std::cout << "[ A ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "A: " << e.what() << std::endl;
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "[ B ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "B: "<< e.what() << std::endl;
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "[ C ]" << std::endl;
		return ;
	} catch( std::exception& e ) {
		std::cerr << "C: " << e.what() << std::endl;
	}
}

/*
	Identify() are just two ways to get the right type of a derived instance.
	While using Base* is possible to verify if NULL is returned from
	dynamic_cast, using Base& we have to catch the exception thrown by it.

	dynamic_cast is performed by runtime, the compiler is not instructed before.
*/
int main ( void ) {
	Base*	p = generate();
	identify(p);
	std::cout << std::endl;
	identify(*p);
	return (0);
}
