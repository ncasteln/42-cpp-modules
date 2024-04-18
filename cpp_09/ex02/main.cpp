/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:24 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/18 13:20:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main ( int argc, char** argv ) {
	try {
		PmergeMe<
			std::vector<unsigned int>,
			std::vector<std::pair<unsigned int, unsigned int> > > vector(argc, argv, VECTOR);
		std::cout << std::endl;
		for (unsigned int i = 0; i < 120; i++)
			std::cout << "*";
		std::cout << std::endl << std::endl;
		PmergeMe<
			std::deque<unsigned int>,
			std::deque<std::pair<unsigned int, unsigned int> > > deque(argc, argv, DEQUE);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
