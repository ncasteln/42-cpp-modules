/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:01 by nico              #+#    #+#             */
/*   Updated: 2024/03/26 08:20:49 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <iomanip>
#include <limits>

class RPN
{
	private:
		std::stack<int> _a;
		std::stack<char> _b;
	public:
		RPN( void );
		~RPN( void );
		RPN( const RPN& );
		RPN& operator=( const RPN& rhs );

		RPN( std::string expr );

		int isOperator( char c ) const;
		int resolveExpr( void );
		void resolveStack( std::stack<int>& stack, char op );
		int resolveOperation( int left, int right, char op );

		void displayStacks( void );

		class InvalidInput;
		enum err_list {
			E_EMPTY,
			E_INVCHAR,
			E_INVEXPR,
			E_ZERO,
			E_OVERFLOW
		};
};

class RPN::InvalidInput: public std::exception
{
	private:
		err_list _n;
	public:
		InvalidInput( err_list n );
		const char* what() const throw();
};

#endif
