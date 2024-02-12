/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 12:44:45 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	@param ClapTrap	*p = &s; an instance of type CT, take the address of ST, but
	when attack, the ST attack is performed.
*/
int main( void ) {
	ScavTrap	s("1111");

	s.attack("dangerous human");

	// ClapTrap	*p = &s;
	// p->attack("blob");
	return (0);
}
