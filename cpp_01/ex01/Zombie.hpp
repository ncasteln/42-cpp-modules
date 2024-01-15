/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:35:13 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 14:09:29 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce( void );
		void init( std::string );
	private:
		std::string	name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif /* __ZOMBIE_HPP__ */
