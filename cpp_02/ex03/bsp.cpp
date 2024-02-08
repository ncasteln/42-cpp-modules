/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:27:18 by nico              #+#    #+#             */
/*   Updated: 2024/02/07 18:28:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void print_areas( Fixed A0, Fixed A1, Fixed A2, Fixed A3) {
	std::cout << "[ AREAS ]" << std::endl;
	std::cout << "A0  " << A0 << std::endl;
	std::cout << "A1  " << A1 << std::endl;
	std::cout << "A2  " << A2 << std::endl;
	std::cout << "A3  " << A3 << std::endl;
	std::cout << "sum " << A1 + A2 + A3 << std::endl;
}

static Fixed calcArea(Point const a, Point const b, Point const c ) {
	Fixed	x =
		((a.getX() * (b.getY() - c.getY())) +
		(b.getX() * (c.getY() - a.getY())) +
		(c.getX() * (a.getY() - b.getY()))) / 2.0f;
	if (x < 0)
		x = x * (-1);
	return (x);
}

static bool isValidArea(Fixed A0, Fixed A1, Fixed A2, Fixed A3) {
	if (A0 > 0 && A1 > 0 && A2 > 0 && A3 > 0)
		return (true);
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	A0;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A0 = calcArea(a, b, c);
	A1 = calcArea(point, a, b);
	A2 = calcArea(point, b, c);
	A3 = calcArea(point, c, a);
	print_areas(A0,A1,A2,A3);
	if ((A1 + A2 + A3) == A0 && isValidArea(A0, A1, A2, A3))
		return (true);
	return (false);
}
