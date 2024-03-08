/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:52:58 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 09:35:25 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "display.hpp"

int main ( void ) {
	int numbers[5] = { 10, 34, 56, 127, 999 };
	::iter(numbers, 5, ::display<int>);
	std::cout << std::endl << std::endl;

	std::string strings[3] = { "Hello", "World", "!!!" };
	::iter(strings, 3, ::display<std::string>);
	std::cout << std::endl << std::endl;

	/* Bigger length than the elements */
	char c[13] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	::iter(c, 13, ::display<char>);
	std::cout << std::endl << std::endl;

	/* 0 length */
	double zero[0];
	::iter(zero, 0, ::display<double>);
	std::cout << std::endl << std::endl;
	return (0);
}
