/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/20 11:23:07 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> // maybe remove
#include <iostream>

static int open_ifstream(std::ifstream& stream, const char* file_name) {
	stream.open(file_name, std::ifstream::in);
	if (!stream)	// ios::operator! same as dbstream.fail()
		return (1);
	return (0);
}

/*
	I decided to open/close the database for every input line, but I could also
	use the followings:
	- dbstream.clear();		// clear error flags
	- dbstream.seekg(0);	// reset offset position to zero
*/
int read_dbstream(BitcoinExchange& input, BitcoinExchange& prev) {
	std::ifstream dbstream;
	std::string db_buff;

	if (open_ifstream(dbstream, "./data.csv")) // for every input it is closed and opened
		return (std::cerr << "Error: fail opening database stream" << std::endl, 1);
	while (getline(dbstream, db_buff)) {
		if (db_buff.empty()) continue ;
		if (dbstream.fail()) {
			std::cerr << "Error: stream state error occured" << std::endl;
			dbstream.close();
			return (1);
		}

		/* db is constructed like the other input instances, but it is not parsed
		since it is not my "responsability" */
		try {
			BitcoinExchange db(db_buff, DATABASE);
			if (input == db) {
				input.displayMatch(db.getValue());
				break ;
			}
			else if (input < db) {
				if (prev.getValue() == -1) // catches when input is in the past in compairson with the first db date
					input.displayMatch(db.getValue());
				else
					input.displayMatch(prev.getValue());
				break ;
			}
			else if (input > db)
				prev = db; // go on but save the previous
		} catch ( std::exception& e ) {
			/* TRY AND CATCH are only ued to jump the first line of the
			database ( or other line with invalid format ) which holds date,exchange_rate string,
			otherwise is not necessary since the database is assumed that contains always correct values */
		}
	};
	if (dbstream.eof()) // catch dates that go over the highest in the future
		input.displayMatch(prev.getValue());
	dbstream.close();
	return (0);
}

int read_instream(std::ifstream& instream, std::string& in_buff) {
	while (getline(instream, in_buff)) { //  && instream.good() check if no errors occure
		try {
			if (instream.fail()) {
				std::cerr << "Error: stream state error occured" << std::endl;
				break ;
			}
			if (in_buff.empty()) continue ;

			std::cout << "Parsing ---> [" << in_buff << "]" << std::endl;

			BitcoinExchange input(in_buff, INPUT); // throws exceptions in case of errors in storing the inputline
			BitcoinExchange prev(DATABASE);	// need to create to remember the lower and not the higher

			if (read_dbstream(input, prev)) // check return value ?
				return (1);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << LINE << std::endl;
	}
	return (0);
}

int main( int argc, char** argv ) {
	std::ifstream instream;
	std::string in_buff;

	if (argc != 2)
		return (std::cerr << "Error: invalid argc" << std::endl, 1);
	if (open_ifstream(instream, argv[1]))
		return (std::cerr << "Error: fail opening input file stream" << std::endl, 1);
	if (read_instream(instream, in_buff)) {
		instream.close();
		return (1);
	}
	instream.close();
	return (0);
}

/* TO CHECK AND TO DO
	- empty line cases
	- double or float ???
	- PROBLEM with exception: what to do in case of open() or reading errors? I think I would to exit()
		// if (instream.fail()) // correct practice ? put a try {} outside ????
		// 	throw std::ios_base::failure("fail occured while reading instream");
	- check limits begin and end of database
		// date bigger then the biggest
		// date lower then the lowest
*/
