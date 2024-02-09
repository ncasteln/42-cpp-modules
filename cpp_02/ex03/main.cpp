/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:45:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* int main (void) {
	Point	a(0.11f, 0.42f);
	std::cout << "[a]" << std::endl;
	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;

	Point	b( a );
	std::cout << "[b]" << std::endl;
	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;

	Point	c;
	c = a;
	std::cout << "[c]" << std::endl;
	std::cout << c.getX() << std::endl;
	std::cout << c.getY() << std::endl;
	return (0);
} */

int main (void) {
	Point	A(0, 0);
	Point	B(5, 5);
	Point	C(10, 0);

	Point	in(3, 2);
	if (bsp(A, B, C, in))
		std::cout << "[the point (3, 2) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (3, 2) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;


	Point	out(111111, -99);
	if (bsp(A, B, C, out))
		std::cout << "[the point (111111, -99) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (111111, -99) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;


	Point	edge(9, 1);
	if (bsp(A, B, C, edge))
		std::cout << "[the point (9, 1) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (9, 1) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;


	Point	edgeFloat(1.5f, 1.5f);
	if (bsp(A, B, C, edgeFloat))
		std::cout << "[the point (1.5f, 1.5f) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (1.5f, 1.5f) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;


	Point	edgeFloatZero(0, 0.01f);
	if (bsp(A, B, C, edgeFloatZero))
		std::cout << "[the point (0, 0.01f) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (0, 0.01f) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;


	Point	smallOutside(9, 1.1111f);
	if (bsp(A, B, C, smallOutside))
		std::cout << "[the point (9, 1.1111f) is INSIDE the triangle]" << std::endl << std::endl;
	else
		std::cout << "[the point (9, 1.1111f) is OUTSIDE (or on the edge) of the triangle]" << std::endl << std::endl;

	return (0);
}
