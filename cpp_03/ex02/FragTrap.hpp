/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 11:25:57 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

/*
	attack() method is not requested by the subject. Added to clarify the
	relationship between parent and derived class, about virtual member functions.
*/
class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		~FragTrap( void );
		FragTrap( const FragTrap& );
		FragTrap& operator=( const FragTrap& );
		FragTrap( std::string name );

		void attack( const std::string& );
		void highFivesGuys(void);
};

#endif /* __FRAGTRAP_HPP__ */
