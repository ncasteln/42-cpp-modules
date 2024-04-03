/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:11:23 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 10:18:01 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__

/*	The pourpose of the exercise is to understand dynamic_cast, which is performed
	runtime. The compiler is not instructed before about the casting.
	The virtual destructor is needed both for inheritance and polymorphism, and
	also in case of dynamic_cast<>.

	-	dynamic_cast<Base*>(derObj) --------> derived to base
	-	dynamic_cast<Derived*>(baseObj) ----> base to derived */
class Base
{
	public:
		virtual ~Base( void ) {};
};

#endif
