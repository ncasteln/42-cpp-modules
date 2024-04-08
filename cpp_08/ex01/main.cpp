/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:26 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/08 11:23:08 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Basic examples */
int main ( void ) {
	try {
		unsigned int N = 5;
		Span s(N);

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
		std::cout << "Error: " << e.what() << std::endl;
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
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }



/*	Copy constructor and assignment operator tests
	To test the copy constructor I added a function which returns the reference
	to the vector, then I tried to modify one and verified if the changes reflected
	on the second.
	To make it work need to add the following to the class:
	std::vector<int>& getCont( void ) { return (this->_container); }; */
// int main( void ) {
	// Span s(3);
	// s.addNumber(1);
	// s.addNumber(2);
	// s.addNumber(3);
	// std::cout << "s before  : ";
	// s.displayContainer();

	// // Copy constructor
	// Span cpy(s);
	// std::cout << "cpy before: ";
	// cpy.displayContainer();

	// s.getCont()[0] = -999999;
	// s.getCont()[1] = -999999;
	// s.getCont()[2] = -999999;
	// std::cout << "s after   : ";
	// s.displayContainer();
	// std::cout << "cpy after : ";
	// cpy.displayContainer();

	// // Assignment operator
	// Span toReassign(3);
	// toReassign.addNumber(-1);
	// toReassign.addNumber(-1);
	// toReassign.addNumber(-1);
	// std::cout << "toReassign before :  ";
	// toReassign.displayContainer();
	// toReassign = s;
	// std::cout << "toReassign after  :  ";
	// toReassign.displayContainer();
	// std::cout << "s                 :  ";
	// s.displayContainer();
	// s.getCont()[0] = 777;
	// s.getCont()[1] = 777;
	// s.getCont()[2] = 777;
	// std::cout << "s                 :  ";
	// s.displayContainer();


	/* Assignment operator should correctly copy the _it */
	/* If not done correctly the iterator is shared! */
	// Span u(5);
	// u.addNumber(1);
	// u.addNumber(2);			// --- u < 1, 2, -, -, - >
	// Span v(5);
	// v = u;					// --- t < 1, 2, [-], -, ->
	// v.addNumber(3);
	// u.displayContainer();
	// v.displayContainer();
	// return (0);
// }



/* Edge cases */
// int main( void ) {
// 	/* one number */
// 	try {
// 		Span one(1);
// 		one.addNumber(10);
// 		std::cout << one.longestSpan() << std::endl;
// 		std::cout << one.shortestSpan() << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}

// 	/* zero number */
// 	try {
// 		Span zero(0);
// 		zero.fillContainer();
// 		std::cout << "LongestSpan  : "<< zero.longestSpan() << std::endl;
// 		std::cout << "ShortestSpan : "<< zero.shortestSpan() << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}

// 	/* negative number initialization - already catched internally by vector constructor */
// 	try {
// 		Span s(-1);
// 		s.addNumber(9);
// 		s.addNumber(-2);
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }

// ******************************************************************************************

/* Use of range of iterators to populate the container */
// int main ( void ) {
// 	try {
// 		unsigned int N = 20;
// 		Span s(N);
// 		s.fillContainer();
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }



/* A lot of number, limit given by subj */
// int main ( void ) {
// 	try {
// 		unsigned int N = 10000;
// 		Span s(N);
// 		s.fillContainer();
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }




/* Use of range of iterators to populate the container */
// int main ( void ) {
// 	try {
// 		unsigned int N = 10;
// 		Span s(N);
// 		s.addNumber(10);
// 		s.addNumber(-12);
// 		s.addNumber(3);
// 		s.addNumber(45);
// 		s.addNumber(87);
// 		s.addNumber(-100);
// 		s.addNumber(89);
// 		s.addNumber(7);
// 		s.addNumber(14);
// 		s.addNumber(132);
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }




/* Try add more numbers than N */
// int main ( void ) {
// 	try {
// 		unsigned int N = 3;
// 		Span s(N);
// 		s.addNumber(5);
// 		s.addNumber(15);
// 		s.addNumber(25);
// 		s.addNumber(00000000);	// catched
// 		s.addNumber(00000000);	//
// 		s.addNumber(00000000);	//
// 		s.addNumber(00000000);	//
// 		s.addNumber(00000000);	//
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
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
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }
