/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:20:59 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 19:12:55 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
// #include <cstdlib>
// #include <ctime>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(static_cast<size_t>(time(NULL)));
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


int main ( void ) {
	//////////// not intantiable because no default type set //////////////////
	// #include <typeinfo>
	// Array<> default_type;
	// std::cout << "Size of default_type[]: " << default_type.size() << std::endl;
	// std::cout << typeid(default_type).name() << std::endl;
	// std::cout << std::endl;

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

	//////////////////////////// const instance ///////////////////////////////
	const Array<double> immutable(10);
	try {
		std::cout << "immutable[5] before: " << immutable[5] << std::endl;
		// immutable[5] = 900.9; // uncomment doesn't compile
		std::cout << "immutable[5] after : " << immutable[5] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	// same behavior as...
	// const int arr[2] = { 5, 7 };
	// arr[0] = 90;
	// arr[1] = 90;
	// which is not possible
	std::cout << std::endl;

	/////////////// copy constructor && assignment op//////////////////////////
	Array<int> ft(42);
	for (int i = 0; i < (int)ft.size(); i++)
		ft[i] = 42;
	Array<int> ft_copy( ft );

	ft_copy[0] = 999;
	ft_copy[20] = 999;
	ft_copy[41] = 999;
	std::cout  << "[ FT content ]" << std::endl;
	for (int i = 0; i < (int)ft.size(); i++)
		std::cout  << "[" << ft[i] << "]";
	std::cout << std::endl;
	std::cout  << "[ FT_COPY content ]" << std::endl;
	for (int i = 0; i < (int)ft_copy.size(); i++)
		std::cout  << "[" << ft_copy[i] << "]";
	std::cout << std::endl << std::endl;

	ft_copy = ft;
	std::cout  << "[ FT content ]" << std::endl;
	for (int i = 0; i < (int)ft.size(); i++)
		std::cout  << "[" << ft[i] << "]";
	std::cout << std::endl;
	std::cout  << "[ FT_COPY content after re-assign ]" << std::endl;
	for (int i = 0; i < (int)ft_copy.size(); i++)
		std::cout  << "[" << ft_copy[i] << "]";
	std::cout << std::endl << std::endl;

	///////////////////////////// out of bounds ///////////////////////////////
	std::cout  << "[ Out of range ]" << std::endl;
	try {
		std::cout  << ft[100000] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		ft[100000] = 9999999;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
