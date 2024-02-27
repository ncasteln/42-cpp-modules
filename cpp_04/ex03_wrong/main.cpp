/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:11 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 17:05:50 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/*	Subject test
	The test provided by the subject contains a controversial problem about
	memory allocation in the main() at src->learnMateria()); and
	src->learnMateria()); basically, it is possible to implement functions
	which fulfill this test, but then is not possible pass instances which are
	on the stack.

	Another way to see the problem is, that the main() is actually wrong: the
	user didn't store properly the value returned by new(), which is a very bad
	practice (learning from C, we never want to lost a pointer!).

	There is not an absolute solution to it, just take a decision:
	• Let the program work with heap. In this case, the things allocated in the
	main will be deleted inside the MateriaSource destructor.
	• Build a different test in which the user doesn't lost the pointer to
	the allocated memory. We assume if someone allocates, then this has to take
	responsability to delete.

	In general, there is no universal solution to understand inside a function,
	if the pointer passed as a parameter points to the heap or to the stack.
	One solution could be passing a flag which indicates that the memory was
	allocated (something like src->learnMateria(new Ice(), ALLOCATED)) or not,
	so that the member can properly delete or not.
	But the problem remains, and the user has not to make mistake by passing
	the wrong flag.

	***************************************************************************
	I implemented the solution in which the program works ONLY if:
	1) The AMateria passed to src->learnMateria() is allocated in main(). If it
	is on the stack the program crashes. The AMateria allocated and passed is
	copied, stored in MateriaSource, and the original used is freed.
	2) When the Character unequip a created Materia, it has to be explicitly
	freed in main(). If not, the destructor of the Character will do it.
	3) Stuff like making 2 different Character trying to equip() the same
	AMateria is not done by the user.
	***************************************************************************
*/



/* main() of the subject, which 'holds' potential memory leaks */
int main ( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return (0);
}



// /* 2 Characters which equip the same materia - it will crash */
// int main ( void ) {
// 	Character		wizard_0("Wizard_0");
// 	Character		wizard_1("Wizard_1");
// 	Ice*			i = new Ice();
// 	MateriaSource	src;
// 	src.learnMateria(i);

// 	AMateria	*tmp_0 = src.createMateria("ice");

// 	wizard_0.equip(tmp_0);
// 	wizard_1.equip(tmp_0);	// this is done by someone who doesn't understand the context

// 	return (0);
// }



/* Simple use of HEAP - no crash no leaks :) */
// int main ( void ) {
// 	Ice*			i = new Ice();
// 	MateriaSource	src;
// 	src.learnMateria(i);
// 	return (0);
// }



/* Simple use of STACK - it will crash */
// int main ( void ) {
// 	Ice				i;
// 	MateriaSource	src;
// 	src.learnMateria(&i);
// 	// crash;
// 	return (0);
// }



/* Unequip materials */
// int main ( void ) {
// 	Character		nico("Nico");
// 	MateriaSource	src;

// 	AMateria*	i = new Ice();
// 	src.learnMateria(i);	// this delete automatically new Ice() no need to do it in main()

// 	AMateria*	tmp = src.createMateria("ice");
// 	nico.equip(tmp);
// 	nico.unequip(0);	// this leaves the item to the floor() / main() - need to be freed

// 	delete tmp;
// 	return (0);
// }



/* Reassignment operator AMateria */
// int main ( void ) {
// 	Ice			i;
// 	Cure		c;
// 	AMateria	*pi = &i;
// 	AMateria	*pc = &c;

// 	*pi = *pc;

// 	std::cout << pi->getType() << std::endl;
// 	std::cout << pc->getType() << std::endl;
// 	return (0);
// }



/* Reassignment operator Ice and AMateria */
// int main ( void ) {
// 	Ice			i0;
// 	Cure		c0;

// 	// i0 = c0; // not possible
// 	std::cout << i0.getType() << std::endl;
// 	std::cout << c0.getType() << std::endl;
// 	std::cout << std::endl;

// 	Ice			i1;
// 	Ice			i2;
// 	i1 = i2;
// 	std::cout << std::endl;

// 	AMateria*	p = &i1;
// 	*p = i0;
// 	std::cout << std::endl;
// 	return (0);
// }



/* Other tests */
// int main ( void ) {
// 	ICharacter*	nico = new Character("Nic");
// 	ICharacter*	minishell = new Character("Minishell");
// 	Ice*		ices = new Ice[8];
// 	for (int idx = 0; idx < 8; idx++)
// 		nico->equip(&ices[idx]);
// 	nico->use(0, *minishell);
// 	nico->use(1, *minishell);
// 	nico->use(2, *minishell);
// 	nico->use(3, *minishell);
// 	nico->use(4, *minishell); // fail

// 	nico->unequip(0); // if not unequipped, crash
// 	nico->unequip(1);
// 	nico->unequip(2);
// 	nico->unequip(3);

// 	delete minishell;
// 	delete nico;
// 	delete [] ices;
// 	return (0);
// }



// int main ( void ) {
// 	Character		nico("Nico");

// 	MateriaSource	src; std::cout << std::endl;

// 	Ice*			ice0 = new Ice(); std::cout << std::endl;
// 	Ice*			ice1 = new Ice(); std::cout << std::endl;

// 	Cure*			cure0 = new Cure(); std::cout << std::endl;
// 	Cure*			cure1 = new Cure(); std::cout << std::endl;

// 	Ice*			ice2 = new Ice(); std::cout << std::endl;
// 	Ice*			ice3 = new Ice(); std::cout << std::endl;


// 	src.learnMateria(cure0); std::cout << std::endl;
// 	src.learnMateria(cure1); std::cout << std::endl;
// 	AMateria*	cure_created = src.createMateria("cure");			// will create from cure1
// 	nico.equip(cure_created); std::cout << std::endl;				// items[0]

// 	src.learnMateria(ice0); std::cout << std::endl;
// 	AMateria*	ice_created = src.createMateria("ice");				// will create from ice0
// 	src.learnMateria(ice1); std::cout << std::endl;
// 	AMateria*	another_ice = src.createMateria("ice");				// will create from ice1
// 	nico.equip(ice_created); std::cout << std::endl << std::endl;	// items[1]
// 	nico.equip(another_ice); std::cout << std::endl << std::endl;	// items[2]

// 	src.learnMateria(ice2); std::cout << std::endl;					// not learned, but automatically freed
// 	src.learnMateria(ice3); std::cout << std::endl << std::endl;	// not learned, but automatically freed

// 	std::cout << nico.getItemsAddress()[0]->getType() << std::endl;
// 	std::cout << nico.getItemsAddress()[1]->getType() << std::endl;
// 	std::cout << nico.getItemsAddress()[2]->getType() << std::endl;

// 	nico.unequip(0);		// IMPORTANT: the items unequipped fall into main()
// 							// therefore they have to be deleted inside its scope.
// 							// The rest is deleted inside the Character.
// 							// "The subject says: The unequip() member function must NOT delete the Materia!"
// 							// and at the same time "f course, the Materias must be deleted when a Character is destroyed."

// 	delete cure_created;
// 	return (0);
// }



/* Character class tests */
// int main ( void ) {
// 	Character	nico("Nico");
// 	Character	nico_clone_0( nico );
// 	Character	nico_clone_1( nico_clone_0 );

// 	std::cout << "nico address -> " << &nico << std::endl;
// 	std::cout << "nico_clone_0 address -> " << &nico_clone_0 << std::endl;
// 	std::cout << "nico_clone_1 address -> " << &nico_clone_1 << std::endl;

// 	std::cout << std::endl << "//////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;

// 	Character	enemy( "enemy" );
// 	Ice*		i0 = new Ice();
// 	nico.equip(i0);

// 	Character	nico_to_reassign("NicoR");
// 	nico_to_reassign = nico;

// 	std::cout << "nico _item address -> " << nico.getItemsAddress() << std::endl;
// 	std::cout << "nico_to_reassign _item address -> " << nico_to_reassign.getItemsAddress() << std::endl << std::endl;

// 	nico.use(0, enemy);				// the slot is empty
// 	nico_to_reassign.use(0, enemy);	// the slot is not empty, therefore he can use it

// 	nico.unequip(0);	// if unequiped() this will have to be freed in main()
// 	delete i0;
// 	return (0);
// }
