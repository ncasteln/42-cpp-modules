/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:48:50 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	ClapTrap	a("A");
	std::cout << std::endl;
	ScavTrap	b("B");
	std::cout << std::endl;
	FragTrap	c("C");
	std::cout << std::endl;
	DiamondTrap	d("D");
	std::cout << std::endl;

	return (0);
}

// int main( void ) {
// 	DiamondTrap	d("5555");
// 	DiamondTrap	e( d );

// 	d.getStatus();
// 	d.attack("enemy");
// 	d.whoAmI();

// 	for (int i = 0; i < 55; i++)
// 		d.attack("enemy");
// 	return (0);
// }
