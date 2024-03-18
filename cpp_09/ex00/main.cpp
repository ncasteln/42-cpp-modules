/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 09:12:28 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	RULES
	- The program uses a DB which holds the value of the bitcoins over time
	- Takes a file as argument with a specific format
	- It calculates the value for each line
*/

// parse database
	// open
// parse infile
	// open
	// while()
		// read line
		// separate by pipe and store in <map>
		// check date format (OR excep)
		// check value format (OR excep)
		// find the correct pair in DB
		// output
// close files


#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

static int openFileStream(int argc, std::ifstream& db, char* ifname, std::ifstream& infile) {
	if (argc != 2) {
		std::cerr << "Error: invalid argc" << std::endl;
		return (1);
	}
	db.open("./data.csv",std::ifstream::in);
	if (!db) {	// ios::operator! same as db.fail()
		std::cerr << "Error: fail opening database" << std::endl;
		return (1);
	}
	infile.open(ifname, std::ifstream::in);
	if (!infile) {
		std::cerr << "Error: fail opening infile" << std::endl;
		db.close();
		return (1);
	}
	return (0);
}

int main( int argc, char** argv ) {
	std::ifstream db;
	std::ifstream infile;
	std::string line;

	if (openFileStream(argc, db, argv[1], infile))
		return (1);
	while (getline(infile, line) && infile.good()) { // infile.good() check if no errors occure
		try {
			std::cout << "Parsing ---> " << line << std::endl;
			BitcoinExchange current(line);
			std::cout << "[ SUCCESS ]" << std::endl << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl << std::endl;
		}
	}
	db.close();
	infile.close();
	return (0);
}

/* TO CHECK AND TO DO
	- empty line cases

*/

/* AFTER PARSING */
// once is correct format the db is read
// either like current.findIn(db) OR current.match(db_line)
// each line of db is transformed using more or less the same constructor
// probably with the small change of the separator "," instead of "|"
