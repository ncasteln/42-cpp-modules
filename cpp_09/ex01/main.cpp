/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:28:57 by nico              #+#    #+#             */
/*   Updated: 2024/03/23 16:14:55 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*	TESTS
	8 9 * 9 - 9 - 9 - 4 - 1 + (42)

	(1 2 *) 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / (15)
	(2 2 /) 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /
	(1 2 +) 5 * 6 - 1 3 * - 4 5 * * 8 /
	(3 5 *) 6 - 1 3 * - 4 5 * * 8 /
	(15 6 -) 1 3 * - 4 5 * * 8 /
	9 (1 3 *) - 4 5 * * 8 /
	(9 3 -) 4 5 * * 8 /
	6 (4 5 *) * 8 /
	(6 20 *) 8 /
	(120 8 /)
	15

	(1 2 +) 3 4 + +
	3 (3 4 +) +
	(3 7 +)
	10

	// small cases like just a number
	(1 2 +)
	3

	// invalid
	(1 2 +) 3 4 +
	3 (3 4 +)
	3 7
*/
int main(int argc, char** argv) {
	if (argc != 2)
		return (std::cerr << "Error: invalid argc" << std::endl, 1);
	try {
		RPN rpn(argv[1]);
		rpn.resolveExpr();
		rpn.displayStacks();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
