/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42phone.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:56:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 16:16:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	call_method(std::string line, PhoneBook *p)
{
	if (line == "EXIT")
		return (1);
	else if (line == "ADD")
		(*p).addContact();
	else if (line == "SEARCH")
		(*p).getAllContact();
	else
		std::cout << "*** Method " << "[" << line << "] doesn't exist ***" << std::endl;
	return (0);
}

int	main(void)
{
	PhoneBook	p;
	std::string	line;

	while (1)
	{
		std::cout << std::endl << "*** Hello! What do you want to do? ***" << std::endl;
		std::cout << "- ADD\n- SEARCH\n- EXIT\n" << std::endl;
		getline(std::cin, line);
		if (std::cin.fail()) {
			std::cerr << "Error: std::cin" <<std::endl;
			break ;
		}
		if (call_method(line, &p))
			break ;
	}
	return (0);
}
