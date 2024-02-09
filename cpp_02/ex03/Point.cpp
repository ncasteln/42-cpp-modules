/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:20:29 by nico              #+#    #+#             */
/*   Updated: 2024/02/09 07:45:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): x_(0), y_(0) {}

Point::~Point( void ) {}

/*
	Init list can be explicitly seen here: if try assign x to x_ in the body,
	it won't work, because it would be re-assignment and not initialization
	of a const variable
*/
Point::Point( const float x, const float y ): x_(x), y_(y) {}

Point::Point( const Point& obj ): x_(obj.x_), y_(obj.y_) {}

/*
	Lazy operator= done only because of the subject requirements which ask for OCC.
*/
Point& Point::operator=( const Point& rhs ) {
	(void) rhs;
	return (*this);
}

Fixed Point::getX( void ) const {
	return (this->x_);
}

Fixed Point::getY( void ) const {
	return (this->y_);
}
