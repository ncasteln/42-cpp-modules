/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:23 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/04 14:24:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

template <class Address, class Length, class Function>
void iter( Address* p, Length l, Function f ) {
	for (Length i = 0; i < l; i++)
		f(p[i]);
}

#endif
