/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 12:41:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
	[ C cast ]
	• Conversion:
		int i = 42;
		double d = i;			// implicit
		double d = (double)i;	// explicit
	• Reinterpretation:
		float f = 420.024f;
		void *v = &f;			// implicit
		void *v = (void *)&f;	// explicit
	• Type qualifier reinterpretation (no bit trasnformation):
		int i = 42;
		int const* c = &i;					// implicit
		int const* c = (int const *)&i;		// explicit
		int* g = c;							// doesn't compile (need to explicit it)
	• Lost accuracy:
		double d = 420.024;
		int i = d;				// -Wconversion will detect
	***
	In general IMPLICIT DEMOTION / DOWNCAST is NOT allowed (and generally discouraged)
	but if I explicitly tell the compiler to do it, it will (but not a good idea)
	***
*/
int main ( void ) {


	return (0);
}
