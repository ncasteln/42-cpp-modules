/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:25:57 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 14:11:00 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name ) {
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].init(name);
	return (horde);
}
