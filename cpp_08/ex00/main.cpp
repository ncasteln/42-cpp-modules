/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:29 by nico              #+#    #+#             */
/*   Updated: 2024/03/09 16:29:55 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>	// std::for_each
#include <vector>
#include <iostream>

#include <ctime>		// std::time()
#include <cstdlib>		// std::srand/rand()

static void displayVector( int item ) {
	std::cout << "[" << item <<  "]" << std::endl;
}


int main ( void ) {
	std::vector<int> vector;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 100 ; i++)
		vector.push_back(std::rand() % 100);
	std::for_each(vector.begin(), vector.end(), displayVector);
	try {
		easyfind(vector, 42); // need implementation
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
