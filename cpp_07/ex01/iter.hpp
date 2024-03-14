/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:51:08 by nico              #+#    #+#             */
/*   Updated: 2024/03/14 14:18:04 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

template <class Address, class Length, class Function>
void iter( Address* p, Length l, Function f ) {
	for (int i = 0; i < l; i++)
		f(p[i]);
}

#endif
