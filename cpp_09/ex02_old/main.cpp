/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:24 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/09 09:02:35 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*	STRUCTURE
	- Decision to take:
		1) Use a template class.
			PRO: it make sense
			CONTRO: dirty code using template.
		2) Include both container inside the class.
			PRO: cleaner code
			CONTRO: performance affected? - there is a container that I don't use
		3) I create the containers outside, and i create a different constructor
		based on the container I pass. So, i have no containers inside the class
		but the class provides only the instance to handle that container (it
		seems almost the same as point number 2, except that I don't have data
		inside the class)

	- If I have 2 container inside the class, I can decide 2 things:
		1) The same instance sorts the nums 2 times, and hold the time for both containers
			PRO: ??? ??? ???
			CON: the code is not so reusable, it's shitty "packet"
		2) I create 2 seaparate instances, one for each container, and do the things separately
			PRO: Not same sense of template class, but at least more than the other
			CON: ??? ??? ???

	-------------------------------------------------------------------------------------------

	POSSIBLE DECISION: use the fucking template class and """""" t o l e r a t e"""""" the thing of having
	everyhting inside the .hpp file. To make it CLEANER:
	- think about maybe creating more HELPER functions to SPLIT more the code ( ie. basic/simple operations )
	- think about having the class definition and AFTER IT the implementation
	- think about another extetical way to write the class, maybe with less indentation
	- don't overthink
*/

int main (int argc, char** argv) {
	try {
		std::vector<int> vector;


		// PmergeMe vector(argc, argv, VECTOR);
		// vector.fordJohnson/*Vector*/();

		// PmergeMe list(argc, argv, LIST);
		// list.fordJohnson/*List*/();

	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
