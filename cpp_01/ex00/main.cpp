/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:53:58 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:40:11 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie	*z1 = newZombie("Heap Zombie");
	randomChump("Stack Zombie");
	delete z1;
	return (0);
}
