/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:39 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/17 12:15:43 by ncasteln         ###   ########.fr       */
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
/*	The job of this constructor is to prepare the two stack. The expression is
	stored in the stack B, whose top will be the first item of the input. */
RPN::RPN( std::string expr ) {
	if (expr.empty())
		throw InvalidInput(E_EMPTY);
	std::string::iterator it = expr.end();
	do {
		--it;
		if (isspace(*it))
			continue ;
		else if (isdigit(*it) || isOperator(*it))
			_b.push(*it);
		else
			throw InvalidInput(E_INVCHAR);
	} while (it != expr.begin());
	if (_b.empty())
		throw InvalidInput(E_EMPTY);
};

// ----------------------------------------------------------- MEMBER FUNCTIONS
bool RPN::isOperator( char c ) const {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int RPN::resolveExpr( void ) {
	while (!_b.empty()) {
		if (VERBOSE) displayStacks();
		while (!isOperator(_b.top())) {
			int tmp = _b.top() - 48;
			_a.push(tmp);
			_b.pop();
			if (_b.empty())  //!_b.empty() added for single number cases therwise becomes empty and segfaults
				throw InvalidInput(E_INVEXPR);
		}
		if (VERBOSE) displayStacks();
		if (_a.size() == 1) {
			if (!_b.empty())
				throw InvalidInput(E_INVEXPR);
			break ;
		}
		if (_a.empty())
			throw InvalidInput(E_INVEXPR);
		resolveStack(_a, _b.top());
		_b.pop();
	}
	if (_a.size() != 1)
		throw InvalidInput(E_INVEXPR);
	return (_a.top());
}

void RPN::resolveStack( std::stack<int>& stack_a, char op ) {
	long r = stack_a.top();
	stack_a.pop();
	long l = stack_a.top();
	stack_a.pop();
	int result = resolveOperation(l, r, op);
	_a.push(result);
}

int RPN::resolveOperation(long l, long r, char op) {
	long result;
	if (op == '+') result = l + r;
	if (op == '-') result = l - r;
	if (op == '*') result = l * r;
	if (op == '/') {
		if (r == 0)
			throw InvalidInput(E_ZERO);
		result = l / r;
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
	std::stack<char> b( _b );

	std::cout << "\033[32mA         |         B\033[0m" << std::endl;
	while (!a.empty() || !b.empty()) {
		if (!a.empty()) {
			std::cout << std::setw(10) << a.top();
			a.pop();
		} else std::cout << std::setw(10) << " ";
		std::cout << "\033[32m|\033[0m";
		if (!b.empty()) {
			std::cout << std::setw(10) << b.top();
			b.pop();
		} else std::cout << std::setw(10) << " ";
		std::cout << std::endl;
	};
	std::cout << "----------------------" << std::endl;
}
