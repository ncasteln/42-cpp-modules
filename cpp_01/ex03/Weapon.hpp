/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:47:28 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:31:52 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon( std::string );
		~Weapon();
		std::string const& getType( void ) const;
		void setType( std::string );
};

#endif /*__WEAPON_HPP__*/
