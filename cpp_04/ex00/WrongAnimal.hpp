/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/15 10:02:08 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		virtual ~WrongAnimal( void );
		WrongAnimal( const WrongAnimal& );
		WrongAnimal& operator=( const WrongAnimal& );

		void makeSound( void ) const;
		std::string getType( void ) const;
	protected:
		std::string _type;
};

#endif /* __WRONGANIMAL_HPP__ */
