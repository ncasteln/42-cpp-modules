/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:44 by nico              #+#    #+#             */
/*   Updated: 2024/03/26 09:12:14 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ------------------------------------------------------------- CANONICAL FORM
RPN::RPN( void ) {};

RPN::~RPN( void ) {};

RPN::RPN( const RPN& obj ):
	_a(std::stack<int>(obj._a)),
	_b(std::stack<char>(obj._b)) {};

RPN& RPN::operator=( const RPN& rhs ) {
	_a = std::stack<int>(rhs._a);
	_b = std::stack<char>(rhs._b);
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/*	CHECK
	- overflows: how fucking detect it ? (see the correct function)
	- something / 0 like 5/0 or 0/0

	FOR EVALUATION
	- I decided to consider valid something like 123++, because the numbers has
	to be under 10, therefore I consider each one of them a char.
*/
/*	The job of this constructor is to prepare the two stack. The expression is
	stored in the stack B, whose top will be the first item of the input. */
RPN::RPN( std::string expr ) {
	if (expr.empty()) // catches "" (empty string)
		throw InvalidInput(E_EMPTY);
	std::string::iterator it = expr.end();
	do {
		--it;
		if (isspace(*it)) // includes newline and other special char for spaces
			continue ;
		else if (isdigit(*it) || isOperator(*it))
			_b.push(*it);
		else
			throw InvalidInput(E_INVCHAR);
	} while (it != expr.begin());
	if (_b.empty()) // catches strings composed only by spaces, means no _b stack is built
		throw InvalidInput(E_EMPTY);
};

// ----------------------------------------------------------- MEMBER FUNCTIONS
int RPN::isOperator( char c ) const {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

int RPN::resolveExpr( void ) {
	while (!_b.empty()) {
		displayStacks();
		while (!isOperator(_b.top())) {
			int tmp = _b.top() - 48;
			_a.push(tmp);
			_b.pop();
			if (_b.empty())  //!_b.empty() added for single number cases therwise becomes empty and segfaults
				throw InvalidInput(E_INVEXPR);
		}
		displayStacks();
		if (_a.size() == 1) {
			if (!_b.empty())
				throw InvalidInput(E_INVEXPR);
			break ;
		}
		resolveStack(_a, _b.top());
		_b.pop();
	}
	if (_a.size() != 1)
		throw InvalidInput(E_INVEXPR);
	return (_a.top());
}

void RPN::resolveStack( std::stack<int>& stack, char op ) {
	if (stack.empty()) // catches the case in which the expression is only operators like "+" or " + - + - +"
		throw InvalidInput(E_INVEXPR);
	int r = stack.top();
	stack.pop();
	int l = stack.top();
	stack.pop();
	int result = resolveOperation(l, r, op);
	_a.push(result);
}

int RPN::resolveOperation(int l, int r, char op) {
	long long result; // added this function just to detect the overflows
	// but I'm not sure that the way to do it is correct, how could i detect them properly ?

	// I transform before making the operation so that the operation it's safe.
	// But what happens if I have (long long) overflow then?
	long long lll = static_cast<long long>(l);
	long long llr = static_cast<long long>(r);

	if (op == '+') result = lll + llr;
	if (op == '-') result = lll - llr;
	if (op == '*') result = lll * llr;
	if (op == '/') {
		if (r == 0)
			throw InvalidInput(E_ZERO); // this is catched runtime, so it'll come before an eventual invalid expression
		result = lll / llr;
	}
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw InvalidInput(E_OVERFLOW);
	return (static_cast<int>(result));
}

// ----------------------------------------------------------------- EXCEPTIONS
RPN::InvalidInput::InvalidInput( err_list n ): _n(n) {}

const char* RPN::InvalidInput::what() const throw() {
	if (_n == E_EMPTY) return ("empty expression");
	if (_n == E_INVCHAR) return ("invalid character");
	if (_n == E_INVEXPR) return ("invalid expression");
	if (_n == E_ZERO) return ("division by zero");
	if (_n == E_OVERFLOW) return ("overflow detected");
	return ("unknown exception");
}

// -------------------------------------------------------------------- DISPLAY
void RPN::displayStacks( void ) {
	std::stack<int> a( _a );
	std::stack<char> b ( _b );

	std::cout << "\033[32mA    |    B\033[0m" << std::endl;
	while (!a.empty() || !b.empty()) {
		if (!a.empty()) {
			std::cout << std::setw(5) << a.top();
			a.pop();
		} else std::cout << std::setw(5) << " ";

		std::cout << "\033[32m|\033[0m";

		if (!b.empty()) {
			std::cout << std::setw(5) << b.top();
			b.pop();
		} else std::cout << std::setw(5) << " ";

		std::cout << std::endl;
	};
	std::cout << "-----------------" << std::endl;
}
