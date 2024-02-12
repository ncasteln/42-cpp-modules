/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:43:35 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

/*
	• virtual void attack( const std::string& ); virtual makes possible that
	the derived classes can choose to override the member function with their
	implementation.
	• virtual void attack( const std::string& ) = 0; would make the member
	function pure, and the derived will have to make their own implementation.
*/
class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( std::string );
		~ClapTrap( void );
		ClapTrap( const ClapTrap& );
		ClapTrap& operator=( const ClapTrap& );

		virtual void attack( const std::string& );
		void takeDamage( unsigned int );
		void beRepaired( unsigned int );
	protected:
		std::string _name;
		int _health;
		int _energy;
		int _attack_damage;
};

#endif /* __CLAPTRAP_HPP__ */
