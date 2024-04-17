/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/17 12:12:42 by ncasteln         ###   ########.fr       */
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

#ifndef VERBOSE
# define VERBOSE	0
#endif

class RPN {
	private:
		std::stack<int> _a;		/* Stack which take the results of _b */
		std::stack<char> _b;	/* Stack populated by the input */
	public:
		RPN( void ); // ---------------------------------------- CANONICAL FORM
		~RPN( void );
		RPN( const RPN& );
		RPN& operator=( const RPN& rhs );
		RPN( std::string expr ); // ------------------------- PARAM CONSTRUCTOR
		bool isOperator( char c ) const; // ------------------- MEMBER FUNCTIONS
		int resolveExpr( void );
		void resolveStack( std::stack<int>& stack, char op );
		int resolveOperation( long left, long right, char op );
		void displayStacks( void ); // ---------------------------------- UTILS
		class InvalidInput; // ------------------------------------- EXCEPTIONS
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
