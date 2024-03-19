/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/19 10:32:53 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	RULES
	- The program uses a dbstream which holds the value of the bitcoins over time
	- Takes a file as argument with a specific format
	- It calculates the value for each line
*/

// parse database
	// open
// parse instream
	// open
	// while()
		// read line
		// separate by pipe and store in <map>
		// check date format (OR excep)
		// check value format (OR excep)
		// find the correct pair in dbstream
		// output
// close files


#include "BitcoinExchange.hpp"
#include <fstream> // maybe remove
#include <iostream>

static int openFileStream(int argc, std::ifstream& dbstream, char* ifname, std::ifstream& instream) {
	if (argc != 2) {
		std::cerr << "Error: invalid argc" << std::endl;
		return (1);
	}
	dbstream.open("./data.csv", std::ifstream::in);
	if (!dbstream) {	// ios::operator! same as dbstream.fail()
		std::cerr << "Error: fail opening database" << std::endl;
		return (1);
	}
	instream.open(ifname, std::ifstream::in);
	if (!instream) {
		std::cerr << "Error: fail opening instream" << std::endl;
		dbstream.close();
		return (1);
	}
	return (0);
}

int main( int argc, char** argv ) {
	std::ifstream dbstream;
	std::ifstream instream;
	std::string in_line;
	std::string db_line;

	if (openFileStream(argc, dbstream, argv[1], instream))
		return (1);
	while (getline(instream, in_line)) { //  && instream.good() check if no errors occure
		try {
			if (in_line.empty()) continue ;

			std::cout << "Parsing ---> [" << in_line << "]" << std::endl;
			BitcoinExchange current(in_line, INPUT);
			std::cout << current << LINE << std::endl;

			dbstream.clear();	// clear error flags
			dbstream.seekg(0);	// reset offset position to zero (instead of close/reopen)
			while (getline(dbstream, db_line)) {
				std::cout << "Database ---> [" << db_line << "]" << std::endl;
				BitcoinExchange match(db_line, DATABASE);
				// overload an operator>
			}
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl << LINE << std::endl;
		}
	}
	dbstream.close();
	instream.close();
	return (0);
}

/* TO CHECK AND TO DO
	- empty line cases
	- ctrl-c with getline()
	- double or float ???
	- print only one digit or what ??? related to quest before
	- PROBLEM with exception: what to do in case of open() or reading errors? I think I would to exit()
		// if (instream.fail()) // correct practice ?
		// 	throw std::ios_base::failure("fail occured while reading instream");
	- >= and <= ???

*/

/* AFTER PARSING */
// once is correct format the dbstream is read
// either like current.findIn(dbstream) OR current.match(dbstream_line)
// each line of dbstream is transformed using more or less the same constructor
// probably with the small change of the separator "," instead of "|"
