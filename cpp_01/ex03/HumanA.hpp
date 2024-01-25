/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:14:30 by nico              #+#    #+#             */
/*   Updated: 2024/01/17 08:32:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA( std::string, Weapon& );
		~HumanA();
		void attack( void );
	private:
		Weapon& w;
		std::string name;
};

#endif /*__HUMANA_HPP__*/
