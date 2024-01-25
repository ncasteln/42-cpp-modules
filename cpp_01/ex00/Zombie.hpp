/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:35:13 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:39:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie( std::string );
		~Zombie();
		void announce( void );
	private:
		std::string	name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif /* __ZOMBIE_HPP__ */
