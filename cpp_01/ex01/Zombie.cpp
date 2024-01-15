/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:37:34 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 14:13:42 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {
	std::cout << "*** KABOOOOOOOOOM! (A zombie exploded!) ***" << std::endl;
}

void Zombie::init( std::string name ) {
	this->name = name;
}

void Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


