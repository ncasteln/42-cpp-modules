/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:01 by nico              #+#    #+#             */
/*   Updated: 2024/03/23 18:08:37 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

class RPN
{
	private:
		std::stack<int> _a; // holds only small expressions
		std::stack<char> _b; // holds the whole expression
		int _result;
	public:
		RPN( void );
		~RPN( void );
		RPN( const RPN& );
		RPN& operator=( const RPN& rhs );

		RPN( std::string expr );

		int isOperator( char c ) const;
		void resolveExpr( void );
		void resolveStack( std::stack<int>& stack, char operand );
		int getResult( void ) const;

		void displayStacks( void );

		class InvalidInput;
		enum err_list {
			E_EMPTY,
			E_INVCHAR,
			E_INVEXPR
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

std::ostream& operator<<( std::ostream& cout, std::stack<int> stack );

#endif
