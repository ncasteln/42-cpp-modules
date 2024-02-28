/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:35 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 17:57:10 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>

/*
	In the exercise I had to try to avoid use too many if/else if/else to
	match the command passed as argument; pointer to function is mandatory.

	• char (*f)( int ); ptr to a function which returns char and take int.
	• char (Harl::*f)( int ); ptr to func member of the Harl class, which
	returns char and take int.
	• char (*f[4])( int ); array of ptr to func.
	• char (Harl::*f[4])( int ); array of ptr to func member of Harl.
*/
class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string );
		std::string getLvl( int );
	private:
		void setLvl( void );
		void setFptr( void );
		std::string lvl[4];
		void (Harl::*f[4])( void );
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif /* __HARL_HPP__ */
