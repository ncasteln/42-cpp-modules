/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:12:29 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/25 18:39:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main ( int argc, char **argv ) {
	Harl		h;
	std::string	s;

	s = "";
	if (argc > 2)
		return (1);
	if (argc == 2)
		s = std::string(argv[1]);
	h.complain(s);
	return (0);
}
