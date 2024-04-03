/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:04:55 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:03:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HANDLE_TYPE_HPP__
# define __HANDLE_TYPE_HPP__

#include <string>
#include <iostream>
#include <cstdlib>		// std::atoi, atof, atol, isprint, isdigit
#include <cmath>		// std::isinf
#include "display.hpp"

void handleChar( std::string );
void handleInt( std::string );
void handleDouble( std::string );
void handleFloat( std::string );
void handleString( std::string );

#endif /* __HANDLE_TYPE_HPP__ */
