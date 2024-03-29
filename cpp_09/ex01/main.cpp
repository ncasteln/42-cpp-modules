/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:28:57 by nico              #+#    #+#             */
/*   Updated: 2024/03/26 08:04:50 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
		return (std::cerr << "Error: invalid argc" << std::endl, 1);
	try {
		RPN rpn(argv[1]);
		int result = rpn.resolveExpr();
		std::cout << "Result [ " << result << " ]" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
