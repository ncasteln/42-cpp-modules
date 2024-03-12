/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:29 by nico              #+#    #+#             */
/*   Updated: 2024/03/12 08:24:09 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Basic examples */
int main ( void ) {
	int N = 5;
	Span s(N);
	try {
		// short 1 / long 200
		s.addNumber(100);
		s.addNumber(11);
		s.addNumber(-100);
		s.addNumber(70);
		s.addNumber(10);

		// short 0 / long 3
		// s.addNumber(1);
		// s.addNumber(2);
		// s.addNumber(0);
		// s.addNumber(-1);
		// s.addNumber(2);

		// short 0 / long 0
		// s.addNumber(42);
		// s.addNumber(42);
		// s.addNumber(42);
		// s.addNumber(42);
		// s.addNumber(42);
		std::cout << "[ s content ] -> ";
		s.displayContainer();
		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}



/* INT limits test */
// int main( void ) {
// 	Span s(2);

// 	try {
// 		s.addNumber(std::numeric_limits<int>::max());
// 		s.addNumber(std::numeric_limits<int>::min());
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return (0);
// }



/* Copy constructor and assignment operator tests */
/*
	To test the copy constructor I added a function which returns the reference
	to the vector, then I tried to modify one and verified if the changes reflected
	on the second.
	std::vector<int>& getCont( void ) { return (this->_container); };
*/
// int main( void ) {
// 	Span s(3);
// 	s.addNumber(3);
// 	s.addNumber(-4);
// 	s.addNumber(17);

// 	// Copy constructor
// 	// Span cpy(s);
// 	// s.getCont()[0] = -100;
// 	// s.getCont()[1] = -100;
// 	// s.getCont()[2] = -100;

// 	// s.displayContainer();
// 	// cpy.displayContainer();

// 	// Assignment operator
// 	// Span toReassign(3);
// 	// toReassign.addNumber(-8);
// 	// toReassign.addNumber(888);
// 	// toReassign.addNumber(-18);
// 	// toReassign = s;

// 	// s.displayContainer();
// 	// toReassign.displayContainer();
// 	return (0);
// }




/* Particular cases */
// int main( void ) {
// 	// one number
// 	// try {
// 	// 	Span one(1);
// 	// 	one.addNumber(10);
// 	// 	std::cout << one.longestSpan() << std::endl;
// 	// 	std::cout << one.shortestSpan() << std::endl;
// 	// } catch (std::exception& e) {
// 	// 	std::cout << e.what() << std::endl;
// 	// }

// 	// zero number
// 	// try {
// 	// 	Span zero(0);
// 	// 	zero.fillContainer();
// 	// 	std::cout << zero.longestSpan() << std::endl;
// 	// 	std::cout << zero.shortestSpan() << std::endl;
// 	// } catch (std::exception& e) {
// 	// 	std::cout << e.what() << std::endl;
// 	// }

// 	// negative number initialization - already catched internally by vector constructor
// 	try {
// 		Span s(-100);
// 		s.addNumber(9);
// 		s.addNumber(-2);
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }



/* Populate container which has already some members */
// int main( void ) {
// 	try {
// 		Span s(5);
// 		s.addNumber(9);
// 		s.addNumber(45);
// 		s.fillContainer();
// 		s.displayContainer();
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }




/* Try add more numbers than N */
// int main ( void ) {
// 	int N = 3;
// 	Span s(N);

// 	try {
// 		s.addNumber(5);
// 		s.addNumber(15);
// 		s.addNumber(25);
// 		s.addNumber(35);	// catched
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return (0);
// }



/* Use of range of iterators to populate the container */
// int main ( void ) {
// 	int N = 10000;
// 	Span s(N);

// 	try {
// 		s.fillContainer();
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return (0);
// }
