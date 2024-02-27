/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:08:14 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/14 14:38:25 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria* _items[4];
	public:
		Character( void );
		~Character( void );
		Character( const Character& );
		Character& operator=( const Character& );

		Character( std::string );

		std::string const& getName( void ) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria** getItemsAddress( void );	// not requested
};

#endif /* __CHARACTER_HPP__ */
