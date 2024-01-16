/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:14:30 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:35:53 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA();
		~HumanA();
		void attack( void );
	private:
		Weapon wa;
		std::string name;
};

#endif /*__HUMANA_HPP__*/
