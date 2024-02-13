/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:58:52 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 10:41:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain& );
		Brain& operator=( const Brain& );
		std::string getIdea( int ) const;
		void setIdea( int, std::string );
	private:
		std::string	_ideas[100];
};

#endif /* __BRAIN_HPP__ */
