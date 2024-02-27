/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 19:37:19 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure( void );
		~Cure( void );
		Cure( const Cure& );
		Cure& operator=( const Cure& );

		AMateria* clone( void );
		void use( ICharacter& );
};

#endif /* __CURE_HPP__ */
