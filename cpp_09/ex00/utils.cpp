/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:15:09 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 08:57:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

static std::string& ltrim( std::string& s, const char* to_trim ) {
	size_t pos = s.find_first_not_of(to_trim);
	s.erase(0, pos);
	return (s);
}

static std::string& rtrim( std::string& s, const char* to_trim ) {
	size_t pos = s.find_last_not_of(to_trim); // start from the end and searches the first that doesnt match
	s.erase(pos + 1); // if not specified 2 values, start from pos until the end
	return (s);
}

std::string& trim( std::string& s, const char* to_trim ) {
	return (ltrim(rtrim(s, to_trim), to_trim));
}
