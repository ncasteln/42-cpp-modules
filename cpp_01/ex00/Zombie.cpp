/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:37:34 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 13:21:37 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ): name(name) {
	std::cout << "*** BLELARRRCCCH! (A zombie is rising up!) ***" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << "*** KABOOOOOOOOOM! (A zombie exploded!) ***" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


