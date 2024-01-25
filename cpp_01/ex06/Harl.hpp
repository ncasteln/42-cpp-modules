/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:35 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/23 11:48:09 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>

class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string );
	private:
		void setLvl( void );
		void setLogMessages( void );
		void log( int );
		std::string lvl[4];
		std::string logs[5];
};

#endif /* __HARL_HPP__ */
