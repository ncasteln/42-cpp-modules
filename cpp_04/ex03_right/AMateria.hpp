/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 09:44:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria( void );
		virtual ~AMateria( void );
		AMateria( const AMateria& );
		virtual AMateria& operator=( const AMateria& );

		AMateria( std::string const& );

		std::string const& getType( void ) const;

		virtual AMateria* clone( void ) = 0;
		virtual void use( ICharacter& target );
};

#endif /* __AMATERIA_HPP__ */
