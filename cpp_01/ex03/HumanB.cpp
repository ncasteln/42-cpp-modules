/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:16:54 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:21:59 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void ) {}

HumanB::~HumanB( void ) {}

void HumanB::attack( void ) {
	std::cout << this->name << " attacks with their " << this->wa.getType() << std::endl;
}
