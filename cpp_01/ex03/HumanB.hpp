/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:14:30 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 18:06:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB( std::string );
		HumanB( std::string, Weapon& );
		~HumanB();
		void attack( void );
		void setWeapon( Weapon& );
	private:
		Weapon* w;
		std::string name;
};

#endif /*__HUMANB_HPP__*/
