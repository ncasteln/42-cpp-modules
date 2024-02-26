/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 08:47:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog& );
		Dog& operator=( const Dog& );

		void makeSound ( void ) const;
};

#endif /* __DOG_HPP__ */
