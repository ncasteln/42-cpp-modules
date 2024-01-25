/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:25:57 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:43:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name ) {
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].init(name);
	return (horde);
}
