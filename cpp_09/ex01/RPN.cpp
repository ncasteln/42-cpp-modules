/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:44 by nico              #+#    #+#             */
/*   Updated: 2024/03/23 16:46:36 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ------------------------------------------------------------- CANONICAL FORM
RPN::RPN( void ) {};

RPN::~RPN( void ) {};

RPN::RPN( const RPN& ) {
	//implement
};

RPN& RPN::operator=( const RPN& rhs ) {
	//implement
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/*	TO DO
	- trim eventual whitespaces at the beginning
	- emptyline cases
	- case "+"
	- overflows
*/
/*	RULES
	- how check this ?	during stack operations or before ?
		// during: maybe the rule is, if in [stack A] there are 2 elements, there is a problem
		// before: n_digits has to be (n_ops + 1) otherwise is INVALID
	- Create 2 stacks A and B, the B is full at the beginning; the top is the first element of the expr
	while (!_b().empty()) && maybe there is just one member in [a]
		1) PUSH everyhting from B to A until the TOP of A is an op
		2) resolve calculation of A
*/
/*	The job of this constructor is to prepare the two stack. The expression is
	stored in the stack B, whose top will be the first item of the expression. */
RPN::RPN( std::string expr ) {
	if (expr.empty())
		throw InvalidInput(E_EMPTY);
	std::string::iterator it = expr.end();
	do {
		--it;
		if (*it == ' ')
			continue ;
		else if (isdigit(*it) || isOperator(*it))
			_c.push(*it);
		else
			throw InvalidInput(E_INVCHAR);
	} while (it != expr.begin());
	displayStacks();
};

// ----------------------------------------------------------- MEMBER FUNCTIONS
int RPN::isOperator( char c ) const {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

void RPN::resolveExpr( void ) {
	while (!_c.empty()) {
		while (!isOperator(_c.top())) {
			int tmp = _c.top() - 48;
			_b.push(tmp);
			_c.pop();
		}

		if (_b.size() == 2)
			resolveStack(_b, _c.top());
		else if (_b.size() == 1) {
			int tmp = _b.top();
			_a.push(tmp);
			_b.pop();
			resolveStack(_a, _c.top());
		}
		else
			resolveStack(_a, _c.top());
		_c.pop();
	}
}

void RPN::resolveStack( std::stack<int>& stack, char op ) {
	// int r = stack.top();
	// stack.pop();
	// int l = stack.top();
	// stack.pop();
	// if (op == '+') _a.push(l + r);
	// if (op == '-') _a.push(l - r);
	// if (op == '*') _a.push(l * r);
	// if (op == '/') _a.push(l / r);
}

// ----------------------------------------------------------------- EXCEPTIONS
RPN::InvalidInput::InvalidInput( err_list n ): _n(n) {}

const char* RPN::InvalidInput::what() const throw() {
	if (_n == E_EMPTY) return ("empty line input");
	if (_n == E_INVCHAR) return ("invalid character");
	return ("unknown exception");
}

// -------------------------------------------------------------------- DISPLAY
void RPN::displayStacks( void ) {
	std::stack<int> a( _a );
	std::stack<int> b( _b );
	std::stack<char> c ( _c );

	std::cout << "\033[32mA    |  B  |    C\033[0m" << std::endl;
	while (!a.empty() || !b.empty() || !c.empty()) {
		if (!a.empty()) {
			std::cout << std::setw(5) << std::right << a.top();
			a.pop();
		} else std::cout << std::setw(5) << " ";

		std::cout << "\033[32m|\033[0m";

		if (!b.empty()) {
			std::cout << std::setw(5) << b.top();
			b.pop();
		} else std::cout << std::setw(5) << " ";

		std::cout << "\033[32m|\033[0m";

		if (!c.empty()) {
			std::cout << std::setw(5) << c.top();
			c.pop();
		} else std::cout << std::setw(5) << " ";

		std::cout << std::endl;
	};
	std::cout << "-----------------" << std::endl;
}

std::ostream& operator<<( std::ostream& cout, std::stack<int> stack ) { // make it template to work with char or int
	while (!stack.empty()) {
		cout << "[ " << stack.top() << " ]" << std::endl;
		stack.pop();
	}
	return (cout);
}




/*

void RPN::resolveExpr( void ) {
	while (!_c.empty()) {
		while (!isOperator(_c.top())) {
			int tmp = _c.top() - 48;
			_b.push(tmp);
			_c.pop();
		}

		if (_b.size() == 2)
			resolveStack(_b, _c.top());
		else if (_b.size() == 1) {
			int tmp = _b.top();
			_a.push(tmp);
			_b.pop();
			resolveStack(_a, _c.top());
		}
		else
			resolveStack(_a, _c.top());
		_c.pop();
	}
}


void RPN::resolveStack( std::stack<int>& stack, char op ) {
	int r = stack.top();
	stack.pop();
	int l = stack.top();
	stack.pop();
	if (op == '+') _a.push(l + r);
	if (op == '-') _a.push(l - r);
	if (op == '*') _a.push(l * r);
	if (op == '/') _a.push(l / r);
}




*/
