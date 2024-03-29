/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:19:58 by nico              #+#    #+#             */
/*   Updated: 2024/03/29 11:51:08 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// parse input - no dups | only pos int | accept "   421 10  3   " or "   421 "  " 10 " 3
// merge every integer inside the selected container type
// sort()

int main (int argc, char** argv) {
	try {
		PmergeMe first(argc, argv);
		first.fordJohnson();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
