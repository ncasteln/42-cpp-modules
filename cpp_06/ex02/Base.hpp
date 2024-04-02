/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:00:15 by nico              #+#    #+#             */
/*   Updated: 2024/04/02 14:57:10 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__

/*
	The pourpose of the exercise is to understand dynamic_cast, which is performed
	runtime. The compiler is not instructed before about the casting.

	In order to be a polymorphic type, the class must have at least one virtual
	function. If your classes are not polymorphic types, the base-to-derived use
	of dynamic_cast will not compile.
	In other words: the virtual destructor is needed to perform dynamic_cast<>

	-	dynamic_cast<Base*>(derObj) --------> derived to base
	-	dynamic_cast<Derived*>(baseObj) ----> base to derived
*/
class Base
{
	public:
		virtual ~Base( void ) {};
};

#endif
