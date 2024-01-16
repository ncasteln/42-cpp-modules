/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:14:27 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:09:22 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
	Both s and *stringPTR can be first declared and then initalized, as opposed
	to references, which need an immediate initialization.
	Reference = something similar as a const pointer, which means, a pointer 
	which points forever to the same variable.
*/
int	main(void) {
	std::string		s;
	std::string*	stringPTR;
	std::string&	stringREF = s;

	s = "HI THIS IS BRAIN";
	stringPTR = &s;

	std::cout
		<< "Address of s -> "<< &s << std::endl
		<< "Address hold by stringPTR ->" << stringPTR << std::endl
		<< "Address hold by stringREF ->" << &stringREF << std::endl;

	std::cout
		<< "Value of s -> "<< s << std::endl
		<< "Value hold by stringPTR ->" << *stringPTR << std::endl
		<< "Value hold by stringREF ->" << stringREF << std::endl;
	return (0);
}
