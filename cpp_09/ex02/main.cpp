/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:19:58 by nico              #+#    #+#             */
/*   Updated: 2024/03/29 17:15:31 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*	STRUCTURE
	- class PmergeMe holds either a vector OR a list.
	- It hold also a clock to retrieve the time
*/

int main (int argc, char** argv) {
	try {
		PmergeMe vector(argc, argv);
		// vector.fordJohnson();

		PmergeMe list(argc, argv);
		// list.fordJohnson();


	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
