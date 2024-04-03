/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:58:33 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 15:54:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

void displayCharInt( double d );
void displayFloatDouble( float f, double d );
void displaySpecial( std::string );
void displayLimits( void );

#endif /* __DISPLAY_HPP__ */
