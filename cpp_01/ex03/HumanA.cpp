/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:16:54 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/17 08:50:56 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA( void ) {}

HumanA::HumanA( std::string name, Weapon& w ): w(w), name(name) {}

void HumanA::attack( void ) {
	std::cout << this->name << " attacks with his " << this->w.getType() << std::endl;
}
