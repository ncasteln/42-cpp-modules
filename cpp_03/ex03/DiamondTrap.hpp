/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 12:58:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
	Diamond problem: It occurs when a class inherits from two classes that have
	a common ancestor, leading to ambiguity. If there is a method in A that
	B and C have overridden, and D does not override it, then which version
	of the method does D inherit: that of B, or that of C?
	A   A         A
	|   |        / \
	B   C       B   C
	 \ /         \ /
	  D           D
	In this context 'shadowing' refers to a member of a derived class which
	"shadows" one in the parent one, because they have the same name.
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
		void getStatus( void );
	private:
		std::string name_;
};

#endif /* __DIAMONDTRAP_HPP__ */
