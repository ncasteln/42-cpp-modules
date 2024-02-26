/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 17:16:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int argc, char** argv ) {
	if (argc != 2) {
		std::cerr << "Error: one argument required" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
