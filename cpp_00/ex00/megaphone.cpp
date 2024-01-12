/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:53:32 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 12:25:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static std::string	ltrim(std::string s) {
	while (*(s.begin()) == ' ' || *(s.begin()) == '\t')
		s.erase(s.begin());
	return (s);
}

static std::string	rtrim(std::string s) {
	while (*(s.end() - 1) == ' ' || *(s.end() - 1) == '\t')
		s.erase(s.end() - 1);
	return (s);
}

int	main(int argc, char **argv) {
	std::string				s;
	std::string::iterator	it;

	argv++;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		while (*argv) {
			s = rtrim(ltrim((std::string)(*argv)));
			if (s.empty()) {
				argv++;
				continue ;
			}
			it = s.begin();
			while (it != s.end()) {
				std::cout << (char)std::toupper(*it);
				it++;
			}
			std::cout << " ";
			argv++;
		}
	}
	std::cout << std::endl;
	return (0);
}
