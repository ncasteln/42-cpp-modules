/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:01 by nico              #+#    #+#             */
/*   Updated: 2024/03/22 17:47:45 by nico             ###   ########.fr       */
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
		std::stack<int> _a;
		std::stack<char> _b; // holds only small expressions
		std::stack<char> _c; // holds the whole expression
	public:
		RPN( void );
		~RPN( void );
		RPN( const RPN& );
		RPN& operator=( const RPN& rhs );

		RPN( std::string expr );

		int isOperand( char c );
		void resolveExpr( void );
		void resolveStackB( void );
		void resolveStackA( char operand );

		void displayStacks( void );

		class InvalidInput;
		enum err_list {
			E_INVCHAR
		};
};

class RPN::InvalidInput: std::exception {
	private:
		int _err_num;
	public:
		InvalidInput( int err_num );
		const char* what() const throw();
};

std::ostream& operator<<( std::ostream& cout, std::stack<char> stack );

#endif
