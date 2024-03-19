/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/19 11:47:44 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			BitcoinExchange input(in_line, INPUT);

			dbstream.clear();				// clear error flags
			dbstream.seekg(0);				// reset offset position to zero (instead of close/reopen)
			BitcoinExchange prev(DATABASE);	// need to create to remember the lower and not the higher

			while (getline(dbstream, db_line)) {
				try {
					BitcoinExchange db(db_line, DATABASE); // i never want that throw exceptions
					if (input == db) {
						input.displayResult(db.getValue());
						std::cout << "STOP      @ " << std::endl << db << std::endl;
						std::cout << "TO RETURN : " << std::endl << db << std::endl;
						break ;
					}
					else if (input > db) {
						// go on but save the previous
						prev = db;
					}
					else {
						std::cout << "STOP      @ " << std::endl << db << std::endl;
						std::cout << "TO RETURN : " << std::endl << prev << std::endl;
						input.displayResult(prev.getValue());
						break ;
					}
				} catch (std::exception& e) {

				}
			}
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << LINE << std::endl;
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
	- check limits begin and end of database
		// date bigger then the biggest
		// date lower then the lowest

*/
