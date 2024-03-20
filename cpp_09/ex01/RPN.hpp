/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:01 by nico              #+#    #+#             */
/*   Updated: 2024/03/20 13:08:03 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <queue>
#include <string>
#include <exception>
#include <iostream>

class RPN
{
	private:
		std::queue<std::string> _data;
	public:
		RPN( void );
		~RPN( void );
		RPN( const RPN& );
		RPN& operator=( const RPN& rhs);

		RPN( char* );

		class InvalidInput;
};

class RPN::InvalidInput: std::exception {
	const char* what() const throw();
};

#endif
