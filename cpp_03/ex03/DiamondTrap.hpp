/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 15:45:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
	Diamond problem: It occurs when a class inherits from two classes that have
	a common ancestor. This can lead to ambiguity and complexity in the
	inheritance hierarchy.
	  A
	 / \
	B   C
	 \ /
	  D
	Virtual base class: by making ScavTrap and FragTrap virtual, we are saying
	that the base object is only ONE. So when creating DiamondTrap, only one
	constructor of ClapTrap is called.
*/
class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( void );
		~DiamondTrap( void );
		DiamondTrap( const DiamondTrap& );
		DiamondTrap& operator=( const DiamondTrap& );
		DiamondTrap( std::string );
		void whoAmI( void );
	private:
		std::string name_;
};

#endif /* __DIAMONDTRAP_HPP__ */
