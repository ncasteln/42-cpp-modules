/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:12 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/05 09:28:48 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>		// std::time()
#include <cstdlib>		// std::srand/rand()

static void displayItems( int item ) {
	std::cout << "[ " << item <<  " ]";
}

static int randomNumber( void ) {
	return (std::rand() % 11);
}
// ****************************** first approach ******************************
/* Normal test */
// int main ( void ) {
// 	int N = 10;
// 	std::vector<int> container(N);	// change container to list or deque, nothing changes
// 	std::srand(static_cast<unsigned int>(std::time(NULL)));
// 	std::generate(container.begin(), container.end(), randomNumber);

// 	std::for_each(container.begin(), container.end(), displayItems);
// 	std::cout << "[end]" << std::endl;

// 	int toFind = 10;
// 	std::cout << "[ Searching first occurrence of " << toFind <<  " ]" << std::endl;
// 	long int itemIndex = easyfind(container, toFind);
// 	if (itemIndex == -1) {
// 		std::cerr << "Item not found" << std::endl;
// 		return (1);
// 	}
// 	std::cout << "Item found @ index [ " << itemIndex << " ]" << std::endl;
// 	return (0);
// }


// **************************** second approach *******************************
int main ( void ) {
	try {
		int N = 10;
		std::vector<int> container(N);	// change container to list or deque, nothing changes
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		std::generate(container.begin(), container.end(), randomNumber);

		std::for_each(container.begin(), container.end(), displayItems);
		std::cout << "[end]" << std::endl;

		int toFind = 10;
		std::cout << "[ Searching first occurrence of " << toFind <<  " ]" << std::endl;
		std::vector<int>::iterator it = easyfind(container, toFind);
		if (it == container.end())
			return (1);
		std::cout << "Item found @ index [ " << std::distance(container.begin(), it) << " ]" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	};
	return (0);
}
