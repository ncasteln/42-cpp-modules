/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:47:28 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:59:56 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <string>
#include <iostream>

/*
	- const ref cannot be used to change the object which refers to.
	- Cannot be re-assigned to another object.
	- We cannot assign a normal ref to a const object.
	- const ref can be bound also to a non-const object, a literal, other expressions and an object of different type.
*/
class Weapon {
	public:
		Weapon();
		~Weapon();
		Weapon( std::string );
		const std::string& getType( void ) const;
		void setType( std::string );
	private:
		std::string type_;
};

#endif /*__WEAPON_HPP__*/
