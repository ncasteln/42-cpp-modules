/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:27:18 by nico              #+#    #+#             */
/*   Updated: 2024/02/02 17:51:50 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed areaTriangle( Point const a, Point const b, Point const c) {
	/*
		[ a.x_(b.y_ + c.y_) + b.x_(a.y_ + c.y_) + c.x_(a.y_ + b.y_) ] / 2
		Overload operator + * and maybe /
	*/

}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	/*
		Area of ABC == ApointB + BpointC + CpointA
	*/
}
