/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:35:13 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 13:25:00 by nico             ###   ########.fr       */
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
