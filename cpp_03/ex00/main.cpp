/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:43:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap	clap("CLAP");

	clap.attack("Ghost");
	clap.takeDamage(6);
	clap.beRepaired(96);
	clap.attack("Ghost");
	clap.attack("Ghost");
	clap.takeDamage(100);
	clap.attack("Ghost");
	clap.takeDamage(100);

	clap.takeDamage(100);
	clap.takeDamage(100);
	clap.takeDamage(100);
	clap.attack("Ghost");
	clap.attack("Ghost");
	clap.attack("Ghost");
	clap.attack("Ghost");
	clap.attack("Ghost");
	clap.beRepaired(96);
	clap.beRepaired(96);
	clap.beRepaired(96);
	clap.beRepaired(96);
	clap.beRepaired(96);
	clap.beRepaired(96);
	return (0);
}
