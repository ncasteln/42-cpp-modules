/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:29 by nico              #+#    #+#             */
/*   Updated: 2024/03/11 17:31:12 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Basic examples */
// int main ( void ) {
// 	int N = 5;
// 	Span s(N);
// 	try {
// 		// short 1 / long 200
// 		s.addNumber(100);
// 		s.addNumber(11);
// 		s.addNumber(-100);
// 		s.addNumber(70);
// 		s.addNumber(10);

// 		// short 0 / long 3
// 		// s.addNumber(1);
// 		// s.addNumber(2);
// 		// s.addNumber(0);
// 		// s.addNumber(-1);
// 		// s.addNumber(2);

// 		// short 0 / long 0
// 		// s.addNumber(42);
// 		// s.addNumber(42);
// 		// s.addNumber(42);
// 		// s.addNumber(42);
// 		// s.addNumber(42);
// 		std::cout << "[ s content ] -> ";
// 		s.displayContainer();
// 		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
// 		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }



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
int main ( void ) {
	int N = 10000;
	Span s(N);

	try {
		s.populateContainer();
		s.displayContainer();
		std::cout << "[ Longest span = " << s.longestSpan() << " ]" << std::endl;
		std::cout << "[ Shortest span = " << s.shortestSpan() << " ]" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
