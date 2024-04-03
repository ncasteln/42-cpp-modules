/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:58:13 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:20:48 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_TYPE_HPP__
# define __GET_TYPE_HPP__

#include <string>

# define CHAR		1
# define STRING		2
# define FLOAT		3
# define DOUBLE		4
# define INT		5
# define LONG		6

int getType( std::string s );
int isChar( std::string s );
int isString( std::string s );
int isFloat( std::string s );
int isDouble( std::string s );
int isInt( std::string s );

#endif /* __GET_TYPE_HPP__ */
