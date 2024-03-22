/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:44 by nico              #+#    #+#             */
/*   Updated: 2024/03/22 18:00:21 by nico             ###   ########.fr       */
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
	- case "34+5-" --- actually it still works because they are from 0 to 9 what do ?
		// NOT COMPLETELY TRUE - because the numbers becomes bigger than 9
	- case "+"
*/
/*	RULES
	- how check this ?	during stack operations or before ?
		// during: maybe the rule is, if in [stack A] there are 2 elements, there is a problem
		// before: n_digits has to be (n_operands + 1) otherwise is INVALID
	- Create 2 stacks A and B, the B is full at the beginning; the top is the first element of the expr
	while (!_b().empty()) && maybe there is just one member in [a]
		1) PUSH everyhting from B to A until the TOP of A is an operand
		2) resolve calculation of A
*/
/*	The job of this constructor is to prepare the two stack. The expression is
	stored in the stack B, whose top will be the first item of the expression. */
RPN::RPN( std::string expr ) {
	std::string::iterator it = expr.end();
	do {
		--it;
		if (*it == ' ')
			continue ;
		else if (isdigit(*it) || isOperand(*it))
			_c.push(*it);
		else
			throw InvalidInput(E_INVCHAR);
	} while (it != expr.begin());
	displayStacks();
};

// ----------------------------------------------------------- MEMBER FUNCTIONS
int RPN::isOperand( char c ) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

void RPN::resolveExpr( void ) {
	while (!_c.empty()) {
		do {
			char tmp = _c.top();
			_b.push(tmp);
			_c.pop();
		} while (!isOperand(_b.top()));
		resolveStackB();
	};
	displayStacks();
}

void RPN::resolveStackB( void ) {
	char operand = _b.top();
	_b.pop();

	if (_b.size() == 2) {
		int a = _b.top() - 48;	// for this can be done a template maybe ??????????
		_b.pop();
		int b = _b.top() - 48;
		_b.pop();
		if (operand == '+') _a.push(a + b);
		if (operand == '-') _a.push(a - b);
		if (operand == '*') _a.push(a * b);
		if (operand == '/') _a.push(a / b);
	}
	else if (_b.size() == 1) {
		int tmp = _b.top() - 48;
		_b.pop();
		_a.push(tmp);
		resolveStackA(operand);
	}
	else { // 0
		resolveStackA(operand);
	}
}

void RPN::resolveStackA( char operand ) {
	int a = _a.top();
	_a.pop();
	int b = _a.top();
	_a.pop();
	if (operand == '+') _a.push(b + a);
	if (operand == '-') _a.push(b - a);
	if (operand == '*') _a.push(b * a);
	if (operand == '/') _a.push(b / a);
}

// ----------------------------------------------------------------- EXCEPTIONS
RPN::InvalidInput::InvalidInput( int err_num ): _err_num(err_num) {}

const char* RPN::InvalidInput::what() const throw() {
	if (_err_num == E_INVCHAR) return ("invalid character");
	return ("unknown exception");
}

// -------------------------------------------------------------------- DISPLAY
void RPN::displayStacks( void ) {
	std::stack<int> a( _a );
	std::stack<char> b( _b );
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

std::ostream& operator<<( std::ostream& cout, std::stack<char> stack ) {
	while (!stack.empty()) {
		cout << "[ " << stack.top() << " ]" << std::endl;
		stack.pop();
	}
	return (cout);
}


/*
RPN::RPN( std::string expr ) {
	std::string::iterator it = expr.end();
	do {
		--it;
		if (*it == ' ')
			continue ;
		else if (isdigit(*it) || isOperand(*it))
			_b.push(*it);
		else
			throw InvalidInput(E_INVCHAR);
	} while (it != expr.begin());
	// displayStacks(_a, _b); // remove
};

void RPN::resolveExpr( void ) {
	int result = 0; // initialize to zero is it right ?
	while (!_b.empty()) {
		displayStacks(_a, _b);
		while (true) { // maybe cause this a check has to be done before ----- ?
			char tmp = _b.top();
			_b.pop();
			_a.push(tmp);
			if (isOperand(_a.top()))
				break ;
		}
		result += resolveStackA();
	}
	std::cout << result << std::endl;
}

int RPN::resolveStackA( void ) {
	char operand = _a.top();
	_a.pop();
	int a = _a.top() - 48;
	_a.pop();
	int b = _a.top()- 48;
	_a.pop();
	if (operand == '+') return (a + b);
	if (operand == '-') return (a - b);
	if (operand == '*') return (a * b);
	if (operand == '/') return (a / b);
}

*/
