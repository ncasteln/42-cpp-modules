/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/14 09:02:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_src[4];
	public:
		MateriaSource( void );
		~MateriaSource( void );
		MateriaSource( const MateriaSource& );
		MateriaSource& operator=( const MateriaSource& );

		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const& type );
};

#endif /* __MATERIASOURCE_HPP__ */
