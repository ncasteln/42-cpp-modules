/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:22:42 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 18:11:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	IMPORTANT NOTE: The main() is provided by the subject and should not be
	changed. The expected result is, for each test case, output with
	"crude spiked club" and "some other type of club".

	HumanA: I change the class HumanA to recieve a REF in the constructor,
	which refers/is bound to the Weapon club declared in the main (The
	constructor won't create a copy of the object).

	HumanB: MAY NOT have a Weapon. From main() I know that takes a string in
	constructor, so beside the same constructor of HumanA, I add another one.
	From main() the is setWeapon() which doesn't take the address of club,
	but club on the stack. The change has to be done in the setWeapon() method
	so that it takes the REF, meaning it take exactly the club in the main()
	stack;
*/
int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
