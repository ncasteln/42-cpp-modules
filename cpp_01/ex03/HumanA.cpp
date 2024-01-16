/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:16:54 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:33:45 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon wa ): name(name), wa(wa) {}

HumanA::~HumanA( void ) {}

void HumanA::attack( void ) {
	std::cout << this->name << " attacks with their " << this->wa.getType() << std::endl;
}
