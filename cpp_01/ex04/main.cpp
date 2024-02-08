/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:04:12 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/26 14:14:52 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

static std::string	replace(std::string line, std::string s1, std::string s2) {
	size_t		i;
	size_t		match;
	std::string	newline;

	i = 0;
	while (i + s1.length() <= line.length()) {
		match = line.find(s1, i);
		if (match == std::string::npos)
			break ;
		else {
			newline.append(line.substr(i, match - i));
			newline.append(s2);
			i += match - i + s1.length();
		}
	}
	newline.append(line.substr(i, line.length() - i));
	return (newline);
}

static int	openFileStream(char *fname, std::fstream& fsin, std::ofstream& fsout) {
	std::string	outfile;

	fsin.open(fname, std::fstream::in);
	if (fsin.fail()) {
		return (1);
	}
	outfile = std::string(fname).append(".replace");
	fsout.open(outfile.c_str(), std::fstream::out | std::fstream::trunc);
	if (fsout.fail()) {
		return (1);
	}
	return (0);
}

static int	error(int n) {
	std::cerr << "Error: ";
	if (n == 1)
		std::cerr << "invalid arguments";
	if (n == 2)
		std::cerr << "Logical error on i/o operation";
	if (n == 3)
		std::cerr << "s1 cannot be empty";
	if (n == 4)
		std::cerr << "Read/writing error on i/o operation";
	std::cerr << std::endl;
	return (n);
}

/*
	Flag for open(): good(), eof(), bad(), fail().
*/
int main (int argc, char **argv) {
	std::fstream	fsin;
	std::ofstream	fsout;
	std::string		line;
	std::string		replaced;

	if (argc != 4)
		return (error(1));
	if (openFileStream(argv[1], fsin, fsout))
		return (error(2));
	if (std::string(argv[2]).empty())
		return (error(3));
	while (getline(fsin, line)) {
		if (fsin.bad())
			return (error(4));
		replaced = replace(line, std::string(argv[2]), std::string(argv[3]));
		fsout << replaced;
		if (fsin.eof())
			break ;
		fsout << std::endl;
	}
	fsin.close();
	fsout.close();
	return (0);
}
