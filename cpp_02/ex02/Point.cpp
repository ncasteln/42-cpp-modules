/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:20:29 by nico              #+#    #+#             */
/*   Updated: 2024/02/02 17:50:42 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): x_(0), y_(0) {}

Point::~Point( void ) {}

Point::Point( const float x, const float y ): x_(x), y_(y) {}

Point::Point( const Point& toCpy ) { /* COPY CONSTR */}

Point& Point::operator=( const Point& toAssign ) { /* ASSIGNMENT OP */}

Fixed Point::getY( void ) {
	return (this->y_);
}

Fixed Point::getX( void ) {
	return (this->x_);
}


