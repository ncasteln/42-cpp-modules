/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:39 by nico              #+#    #+#             */
/*   Updated: 2024/04/17 12:16:38 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int open_ifstream(std::ifstream& stream, const char* file_name) {
	stream.open(file_name, std::ifstream::in);
	if (!stream)
		return (std::cerr << "Error: fail opening INPUT file stream" << std::endl, 1);
	return (0);
}

/*	@ db_stream.clear(); reset/clear the errors
	@ db_stream.seekg(0); move the position of reading to the beginning
	@ if(dbstra.eof()) catches dates which goes over the end of db */
int read_db_stream(BitcoinExchange& input, std::ifstream& db_stream) {
	std::string db_line;

	db_stream.clear();
	db_stream.seekg(0);
	if (db_stream.fail()) {
		std::cerr << "Error: DATABASE stream state error occured" << std::endl;
		db_stream.close();
		return (1);
	}
	BitcoinExchange prev(DATABASE);
	while (getline(db_stream, db_line)) {
		if (db_stream.fail()) {
			std::cerr << "Error: DATABASE stream state error occured" << std::endl;
			db_stream.close();
			return (1);
		}
		if (db_line.empty()) continue ;
		BitcoinExchange db(db_line, DATABASE);
		if (input.findMatch(db, prev))
			break ;
	};
	if (db_stream.eof())
		input.displayMatch(prev.getValue());
	return (0);
}

/*	Conventionally a database starts with a header describing the content, so I
	assume that the first line is defined by external and I don't parse it. */
int read_in_stream(std::ifstream& in_stream ) {
	std::ifstream db_stream;
	std::string in_line;

	bool header = true;
	if (open_ifstream(db_stream, "./data.csv"))
		return (std::cerr << "Error: fail opening DATABASE stream" << std::endl, 1);
	while (getline(in_stream, in_line)) {
		if (in_stream.fail()) {
			std::cerr << "Error: INPUT stream state error occured" << std::endl;
			break ;
		}
		if (header) {
			header = false;
			continue ;
		}
		if (in_line.empty()) continue ;
		try {
			BitcoinExchange input(in_line, INPUT);
			if (read_db_stream(input, db_stream))
				return (1);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	db_stream.close();
	return (0);
}

/*	Since some stream errors could occure, in such cases I completely exit
	from the program. */
int main( int argc, char** argv ) {
	std::ifstream in_stream;

	if (argc != 2)
		return (std::cerr << "Error: invalid argc" << std::endl, 1);
	if (open_ifstream(in_stream, argv[1]))
		return (1);
	if (read_in_stream(in_stream)) {
		in_stream.close();
		return (1);
	}
	in_stream.close();
	return (0);
}
