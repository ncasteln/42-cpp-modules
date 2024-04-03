/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:58:39 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:19:09 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"

// -------------------------------------------------------------------- DISPLAY
/*	The function is created to avoid repetition between codes, since it is a
	common repeated pattern. */
static void displayChar( int i ) {
	char c = 0;
	if (i >= 0 && i <= 127) {
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << "char    : '" << c << "'" << std::endl;
		else
			std::cout << "char    : not printable" << std::endl;
	}
	else
		std::cout << "char    : impossible" << std::endl;
}

void displayCharInt( double d ) {
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) { // substitute ---------- !!!!!
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
	}
	else { // i and c are calculated, c can be out of range too or not displayable
		int i = static_cast<int>(d);
		displayChar(i);
		std::cout << "int     : " << i << std::endl;
	}
}

void displayFloatDouble( float f, double d ) {
	std::cout << "float   : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << d << std::endl;
}

/*	Displays special values like nan, infinity and overflows. The f is not
	printed when "impossible" is passed as a parameter.	*/
void displaySpecial( std::string s ) {
	std::cout << "char   : impossible" << std::endl;
	std::cout << "int    : impossible" << std::endl;
	std::cout << "float  : " << s << (s == "impossible" ? "" : "f") << std::endl;
	std::cout << "double : " << s << std::endl;
}

/*	Not required by the subject, it is still useful to check the range limits
	of the required types. */
void displayLimits( void ) {
	std::cout << "CHAR (8 bits) min: " << 0 << std::endl;
	std::cout << "CHAR (8 bits) max: " << 127 << std::endl << std::endl;
	std::cout << "INT (32 bits) min: " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "INT (32 bits) max: " << std::numeric_limits<int>::max() << std::endl << std::endl;
	std::cout << "FLOAT (32 bits) min: " << std::fixed << std::numeric_limits<float>::min() << std::endl;
	std::cout << "FLOAT (32 bits) max: " << std::fixed << std::numeric_limits<float>::max() << std::endl << std::endl;
	std::cout << "LONG (64 bits) min: " << std::numeric_limits<long>::min() << std::endl;
	std::cout << "LONG (64 bits) max: " << std::numeric_limits<long>::max() << std::endl << std::endl;
	std::cout << "LONG LONG (64 bits) min: " << std::numeric_limits<long long>::min() << std::endl;
	std::cout << "LONG LONG (64 bits) max: " << std::numeric_limits<long long>::max() << std::endl << std::endl;
	std::cout << "DOUBLE (64 bits) min: " << std::fixed << std::numeric_limits<double>::min() << std::endl;
	std::cout << "DOUBLE (64 bits) max: " << std::fixed << std::numeric_limits<double>::max() << std::endl << std::endl;
}
