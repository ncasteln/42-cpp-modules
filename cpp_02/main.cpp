/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:25:04 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/31 09:23:10 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdio.h>

int main (void) {
	float	sum = 0.11f + 0.11f + 0.11f;
	if (sum == 0.33f)
		std::cout << "The sum seems correct! --> " << std::fixed << std::setprecision(20) << sum << std::endl;
	else
		std::cout << "The sum seems NOT correct! --> " << std::fixed << std::setprecision(20) << sum << std::endl;


	float	dsum = 0.11 + 0.11 + 0.11;
	if (dsum == 0.33)
		std::cout << "The sum seems correct! --> " << std::fixed << std::setprecision(20) << dsum << std::endl;
	else
		std::cout << "The sum seems NOT correct! --> " << std::fixed << std::setprecision(20) << dsum << std::endl;
	return (0);
}
