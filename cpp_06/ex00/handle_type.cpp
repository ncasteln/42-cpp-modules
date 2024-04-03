/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:04:41 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:17:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_type.hpp"

void handleChar( std::string s ) {
	std::cout << "[ Type detection: " << "CHAR" << " ]" << std::endl;
	char c = *s.c_str();
	int i = static_cast<int>(c);
	displayCharInt(static_cast<double>(i));
	displayFloatDouble(static_cast<float>(i), static_cast<double>(i));
}

void handleInt( std::string s ) {
	std::cout << "[ Type detection: " << "INT" << " ]" << std::endl ;
	long l = std::atol(s.c_str());
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		throw std::invalid_argument("int overflow");
	int i = std::atoi(s.c_str());
	displayCharInt(static_cast<double>(i));
	displayFloatDouble(static_cast<float>(i), static_cast<double>(i));
}

/*	handleFloat() and handleDouble() are very similar to each other, but the
	subject explicits the exact steps that should be performed, therefore the
	repetition is left as it is. */
void handleFloat( std::string s ) {
	std::cout << "[ Type detection: " << "FLOAT" << " ]" << std::endl ;
	float f = static_cast<float>(std::atof(s.c_str()));
	double d = static_cast<double>(f);
	displayCharInt(d);
	displayFloatDouble(f, d);
}

void handleDouble( std::string s ) {
	std::cout << "[ Type detection: " << "DOUBLE" << " ]" << std::endl ;
	double d = std::atof(s.c_str());
	float f = static_cast<float>(d);
	displayCharInt(d);
	displayFloatDouble(f, d);
}

/*	Handles nan, nanf, +inf, +inff, -inf, -inff. */
void handleString( std::string s ) {
	std::cout << "[ Type detection: " << "STRING" << " ]" << std::endl ;
	if (s == "nan" || s == "+inf" || s == "inf" || s == "-inf")
		displaySpecial(s);
	else if (s == "nanf" || s == "+inff" || s == "inff" || s == "-inff")
		displaySpecial(s.erase(s.size() - 1));
	else
		throw std::invalid_argument("cannot convert a string");
}
