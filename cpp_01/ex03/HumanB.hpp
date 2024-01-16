/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:14:30 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:19:45 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB();
		~HumanB();
		void attack( void );
	private:
		Weapon wa;
		std::string name;
};

#endif /*__HUMANB_HPP__*/
