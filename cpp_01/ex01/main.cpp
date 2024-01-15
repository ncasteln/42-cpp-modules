/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:53:58 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 14:20:26 by nico             ###   ########.fr       */
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
