/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:17:02 by nico              #+#    #+#             */
/*   Updated: 2024/02/02 17:53:20 by nico             ###   ########.fr       */
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
		Point ( const float, const float );

		Fixed getY( void );
		Fixed getX( void );
};

#endif /* __POINT_HPP__ */
