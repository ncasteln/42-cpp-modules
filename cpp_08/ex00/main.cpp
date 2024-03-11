/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:29 by nico              #+#    #+#             */
/*   Updated: 2024/03/11 09:03:50 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>	// std::for_each
#include <iostream>

#include <vector>
#include <list>
#include <deque>

#include <stack>		// lifo
#include <queue>		// fifo

#include <ctime>		// std::time()
#include <cstdlib>		// std::srand/rand()


// ------------------------------------------------------- VECTOR, LIST & DEQUE
static void displayItems( int item ) {
	std::cout << "[ " << item <<  " ]";
}

static int randomNumber( void ) {
	return (std::rand() % 11);
}

int main ( void ) {
	int N = 10;
	std::vector<int> container(N);	// change container to list or deque, nothing changes
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::generate(container.begin(), container.end(), randomNumber);

	std::for_each(container.begin(), container.end(), displayItems);
	std::cout << "[end]" << std::endl;

	int toFind = 10;
	std::cout << "[ Searching first occurrence of " << toFind <<  " ]" << std::endl;
	long int itemIndex = easyfind(container, toFind);
	if (itemIndex == -1) {
		std::cerr << "Item not found" << std::endl;
		return (1);
	}
	std::cout << "Item found @ index [ " << itemIndex << " ]" << std::endl;
	return (0);
}



// ---------------------------------------------------------------------- STACK
// void displayStackItems( std::stack<int> stackA ) {
// 	std::stack<int> stackB;
// 	while (!stackA.empty()) {
// 		std::cout << "[ " << stackA.top() << " ]" << std::endl;
// 		stackB.push(stackA.top());
// 		stackA.pop();
// 	}
// 	while (!stackB.empty()) {
// 		stackA.push(stackB.top());
// 		stackB.pop();
// 	}
// }

// int main ( void ) {
// 	std::stack<int> stackA;
// 	std::srand(static_cast<unsigned int>(std::time(NULL)));
// 	for (int i = 0; i < 10 ; i++)
// 		stackA.push(std::rand() % 11);

// 	displayStackItems(stackA);

// 	int toFind = 10;
// 	std::cout << "[ Searching first occurrence of " << toFind <<  " ]" << std::endl;
// 	long int itemIndex = easyfind(stackA, toFind);
// 	if (itemIndex == -1) {
// 		std::cerr << "Item not found" << std::endl;
// 		return (1);
// 	}
// 	std::cout << "Item found @ index [ " << itemIndex << " ]" << std::endl;

// 	return (0);
// }
