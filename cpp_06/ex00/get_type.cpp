/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:56:36 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:20:36 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_type.hpp"

/*	Here the actual type of the string passed in is detected. From this type,
	the other are obtained by using the static_cast<> */
int getType( std::string s ) {
	int (*f[5])( std::string );
	f[0] = &isChar;
	f[1] = &isString;
	f[2] = &isFloat;
	f[3] = &isDouble;
	f[4] = &isInt;
	int i = 0;
	while (i < 6) {
		if (f[i](s))
			return (f[i](s));
		i++;
	}
	return (0);
}

int isChar( std::string s ) {
	if (s.size() == 1 && !isdigit(s[0]))
		return (CHAR);
	return (0);
}

/*	The followings things are checked: if the there are 2 dots, and the result
	of finding them starting from left and from the right is different, means
	that they are 2 dots; only one sign is accepted; convered case of '.f';
	'f' is accepted only if at the end and a dot is present. */
int isString( std::string s ) {
	bool dot = true;

	if (s.find('.') == std::string::npos)
		dot = false;
	if (dot && (s.find('.') != s.rfind('.')))
		return (STRING);
	std::string::iterator it = s.begin();
	if (*it == '-' || *it == '+')
		it++;
	if (*it == '.' && *(it + 1) == 'f')
		return (STRING);
	while (it != s.end()) {
		if (it == --(s.end()) && dot && *it == 'f')
			break ;
		if (!isdigit(*it) && *it != '.')
			return (STRING);
		it++;
	}
	return (0);
}

int isFloat( std::string s ) {
	if (s.find('.') != std::string::npos)
		if (*(--(s.end())) == 'f')
			return (FLOAT);
	return (0);
}

int isDouble( std::string s ) {
	if (s.find('.') != std::string::npos)
		return (DOUBLE);
	return (0);
}

/*	isInt() is not necessary but was nice to have it to work with function
	pointers in getType() function. */
int isInt( std::string s ) {
	(void)s;
	return (INT);
}
