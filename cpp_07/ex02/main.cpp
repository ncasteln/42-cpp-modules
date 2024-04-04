/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:52 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

/* Various tests */
int main ( void ) {
	//// #include <typeinfo>
	////////// not intantiable because no default type set //////////////////
	//// Array<> default_type;
	//// std::cout << "Size of default_type[]: " << default_type.size() << std::endl;
	//// std::cout << typeid(default_type).name() << std::endl;
	//// std::cout << std::endl;

	try {
		Array<char> empty;
		std::cout << "Size of empty[]: " << empty.size() << std::endl;
		std::cout << std::endl;

		Array<int> numbers(10);
		std::cout << "Size of numbers[]: " << numbers.size() << std::endl;
		std::cout << "numbers[1] before: " << numbers[1] << std::endl;
		std::cout << "numbers[5] before: " << numbers[5] << std::endl;
		std::cout << "numbers[7] before: " << numbers[7] << std::endl;
		numbers[1] = 100;
		numbers[5] = 500;
		numbers[7] = 700;
		std::cout << "numbers[1] after : " << numbers[1] << std::endl;
		std::cout << "numbers[5] after : " << numbers[5] << std::endl;
		std::cout << "numbers[7] after : " << numbers[7] << std::endl;
		std::cout << std::endl;

		//////////////////////////// strings //////////////////////////////////////
		Array<std::string> strings(3);
		std::cout << "Size of strings[]  : " << strings.size() << std::endl;
		std::cout << "strings[0] before : " << strings[0] << std::endl;
		std::cout << "strings[1] before : " << strings[1] << std::endl;
		std::cout << "strings[2] before : " << strings[2] << std::endl;
		strings[0] = "HelloNico";
		strings[1] = "This is 42";
		strings[2] = "!£$%&/()1234567890";
		std::cout << "strings[0] after  : " << strings[0] << std::endl;
		std::cout << "strings[1] after  : " << strings[1] << std::endl;
		std::cout << "strings[2] after  : " << strings[2] << std::endl;
		std::cout << std::endl;

		///////////// copy constructor && assignment op//////////////////////////
		Array<int> ft(10);
		for (size_t i = 0; i < ft.size(); i++)
			ft[i] = 42;

		Array<int> ft_copy( ft ); // verify that modifying the copy doesnt affect the original
		ft_copy[0] = 999;
		ft_copy[4] = 999;

		std::cout  << "[ FT content ]" << std::endl;
		for (size_t i = 0; i < ft.size(); i++)
			std::cout  << "[" << ft[i] << "]";
		std::cout << std::endl;
		std::cout  << "[ FT_COPY content ]" << std::endl;
		for (size_t i = 0; i < ft_copy.size(); i++)
			std::cout  << "[" << ft_copy[i] << "]";
		std::cout << std::endl << std::endl;

		ft_copy = ft; // verify that re-assigning the copy, takes the content of the original
		std::cout  << "[ FT content ]" << std::endl;
		for (size_t i = 0; i < ft.size(); i++)
			std::cout  << "[" << ft[i] << "]";
		std::cout << std::endl;
		std::cout  << "[ FT_COPY content after re-assign ]" << std::endl;
		for (size_t i = 0; i < ft_copy.size(); i++)
			std::cout  << "[" << ft_copy[i] << "]";
		std::cout << std::endl << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}



/* const tests */
// int main ( void ) {
// 	// const int arr[3] = { 1,2,3 };
// 	// arr[0] = 99;
// 	const Array<int> immutable(10);
// 	try {
// 		std::cout << "immutable[5] before: " << immutable[5] << std::endl;
// 		// const int n = immutable[5];	// uncomment doesn't compile
// 		// immutable[5] = 999; 			// uncomment doesn't compile
// 		std::cout << "immutable[5] after : " << immutable[5] << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }


/* Exception tests */
// int main ( void ) {
// 	Array<int> ft(10);

// 	std::cout  << "[ Out of range ]" << std::endl;
// 	try {
// 		std::cout  << ft[100000] << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	try {
// 		ft[100000] = 9999999;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// }



/* Subject main() */
/* Contains a conversion problem */
// #include <cstdlib>
// #include <ctime>
// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(static_cast<unsigned int>(time(NULL)));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;	// copy constructor
//         Array<int> test(tmp);		// same
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try	// invalid access
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try // invalid access
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
