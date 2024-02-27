/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 19:18:48 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource( void ) {};
		virtual void learnMateria( AMateria* ) = 0;
		virtual AMateria* createMateria( std::string const& type ) = 0;
};

#endif /* __IMATERIASOURCE_HPP__ */
