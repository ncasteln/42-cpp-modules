/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:53:58 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:44:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	int		N = 10;
	Zombie	*horde;

	horde = zombieHorde(N, "Heap zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
