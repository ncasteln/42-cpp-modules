/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:27 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/04 09:14:46 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "display.hpp"
#include "addOne.hpp"

int main ( void ) {
	int numbers[5] = { 10, 34, 56, 127, 999 };
	::iter(numbers, 5, ::display<int>);
	std::cout << std::endl << std::endl;

	std::string strings[3] = { "Hello", "World", "!!!" };
	::iter(strings, 3, ::display<std::string>);
	std::cout << std::endl << std::endl;

	std::cout << "[ bigger length ]" << std::endl;
	char c[13] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	::iter(c, 13, ::display<char>);
	std::cout << std::endl << std::endl;

	std::cout << "[ zero length ]" << std::endl;
	double zero[0];
	::iter(zero, 0, ::display<double>);
	std::cout << std::endl << std::endl;

	std::cout << "[ Not init ]" << std::endl;
	int init[10];
	::iter(init, 10, ::display<int>);
	std::cout << std::endl << std::endl;

	std::cout << "[ addOne ]" << std::endl;
	::iter(c, 13, ::addOne<char>);
	::iter(c, 13, ::display<char>);
	std::cout << std::endl << std::endl;

	::iter(strings, 3, ::addOne<std::string>);	// add char like hello+=W ---> helloW
	::iter(strings, 3, ::display<std::string>);
	std::cout << std::endl << std::endl;
	return (0);
}
