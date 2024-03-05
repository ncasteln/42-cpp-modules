/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:00:15 by nico              #+#    #+#             */
/*   Updated: 2024/03/05 15:55:17 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__

/*
	In order to be a polymorphic type, your class must have at least one virtual
	function. If your classes are not polymorphic types, the base-to-derived use
	of dynamic_cast will not compile.
	In other words: virtual destructor is needed to perform dynamic_cast<>

	Exmaple.
	dynamic_cast<Base*>(derObj) --------> derived to base
	dynamic_cast<Derived*>(baseObj) ----> base to derived
*/
class Base
{
	public:
		virtual ~Base( void ) {};
};

#endif
