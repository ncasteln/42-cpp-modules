/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:17:02 by nico              #+#    #+#             */
/*   Updated: 2024/02/07 18:24:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

#include "Fixed.hpp"

class Point {
	private:
		const Fixed	x_;
		const Fixed	y_;
	public:
		Point( void );
		~Point( void );
		Point( const Point& );
		Point& operator=( const Point& );
		Point( const float, const float );
		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* __POINT_HPP__ */
