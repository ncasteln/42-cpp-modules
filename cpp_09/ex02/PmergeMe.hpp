/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:55 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/18 12:22:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include "utils.hpp"

#ifndef	VERBOSE
# define VERBOSE	false	/* Grade of verbosity for the output */
#endif

template <typename T, typename U>
class PmergeMe {
	private:
		T _container;
		e_cont _type;
		void parse( int argc, char** argv ); // ----------------------- PARSING
		PmergeMe( void ); // ----------------------------------- CANONICAL FORM
	public:
		~PmergeMe( void );
		PmergeMe( const PmergeMe& );
		PmergeMe& operator=( const PmergeMe& );
		PmergeMe( int argc, char** argv, e_cont type ); // -- PARAM CONSTRUCTOR
		class InvalidInput; // ------------------------------------- EXCEPTIONS
		typedef enum e_err {
			E_INVCHAR,
			E_EMPTY,
			E_OVERFLOW,
			E_SORTED
		}	e_err;
};

// ------------------------------------------------------------- CANONICAL FORM
template <typename T, typename U> PmergeMe<T, U>::PmergeMe( void ) {};
template <typename T, typename U> PmergeMe<T, U>::~PmergeMe( void ) {};
template <typename T, typename U> PmergeMe<T, U>::PmergeMe( const PmergeMe& obj ) {
	_type = obj._type;
	_container = obj._container;
}
template <typename T, typename U> PmergeMe<T, U>& PmergeMe<T, U>::operator=( const PmergeMe& rhs ) {
	_type = rhs._type;
	_container = rhs._container;
	return (*this);
}

// ---------------------------------------------------------- PARAM CONSTRUCTOR
template <typename T, typename U>
PmergeMe<T, U>::PmergeMe( int argc, char** argv, e_cont type ): _type(type) {
	clock_t start = clock();
	parse(argc, argv);
	displayCont(_container, "[ Before ]");
	U pair_container = pairing<T,U>(_container);
	merge(pair_container);
	verbose("[ MERGING ]", createChain<T>(pair_container, MAIN), createChain<T>(pair_container, PEND));
	T result_container = insertion(_container, pair_container, _type);
	clock_t end = clock();
	displayCont(result_container, "[ After ]");
	displayTime(_container.size(), _type, static_cast<double>(end-start), result_container);
}

// --------------------------------------------------------------------- PARSER
template <typename T, typename U>
void PmergeMe<T,U>::parse( int argc, char** argv ) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg.find_first_not_of("1234567890 \t") != std::string::npos)
			throw InvalidInput(E_INVCHAR);
		if (extract_numbers(arg, _container))
			throw InvalidInput(E_OVERFLOW);
	};
	if (_container.empty())
		throw InvalidInput(E_EMPTY);
	if (isSorted(_container))
		throw InvalidInput(E_SORTED);
};

// ----------------------------------------------------------------- EXCEPTIONS
template <typename T, typename U>
class PmergeMe<T,U>::InvalidInput: public std::exception {
	public:
		InvalidInput( e_err code );
	private:
		e_err _code;
		const char* what() const throw();
};

template<typename T, typename U>
PmergeMe<T,U>::InvalidInput::InvalidInput(e_err code): _code(code) {}

template<typename T, typename U>
const char* PmergeMe<T, U>::InvalidInput::what() const throw() {
	if (_code == E_INVCHAR) return ("invalid character");
	if (_code == E_EMPTY) return ("empty input");
	if (_code == E_SORTED) return ("numbers are already sorted");
	if (_code == E_OVERFLOW) return ("input overflows");
	return ("unknown error");
}

#endif /* __PMERGEME_HPP__ */
