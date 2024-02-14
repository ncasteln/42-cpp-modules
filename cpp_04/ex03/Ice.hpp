/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/14 14:41:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice( void );
		~Ice( void );
		Ice( const Ice& );
		Ice& operator=( const Ice& );

		AMateria* clone( void );
		void use( ICharacter& );
};

#endif /* __ICE_HPP__ */
