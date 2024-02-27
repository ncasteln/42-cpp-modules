/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:11 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/27 08:22:10 by ncasteln         ###   ########.fr       */
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

	A way to see the problem is, that the main() is actually wrong: the user
	didn't store properly the value returned by new(), which is a very bad
	practice (learning from C, we never want to lost a pointer!). Also, it is
	usually better that everything is allocated in the main() is deleted inside
	it, and everything allocated by the class, is deleted inside it.

	So, since there is not an absolute solution to it, just take a decision:
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
	My solution changes the main() provided, sos that the allocated memory by
	the main() has not to be handled by src->learnMateria(). This istance,
	makes a copy of it, so that it'll delete its own stuff. The same will do
	the Character, which will do a copy of the AMateria passed to it, and it
	will delete its own stuff. Particular case is whenit unequips items, whose
	address need to be saved.
	***************************************************************************
*/



/* modified main() of the subject */
// int main ( void ) {
// 	IMateriaSource* src = new MateriaSource();
// 	Ice*	i = new Ice();
// 	Cure*	c = new Cure();
// 	src->learnMateria(i);
// 	src->learnMateria(c);
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete i;
// 	delete c;
// 	return (0);
// }



/* Simple use of HEAP - no crash no leaks :) */
// int main ( void ) {
// 	Ice*			i = new Ice();
// 	MateriaSource	src;
// 	src.learnMateria(i);
// 	delete i;
// 	return (0);
// }



/* Simple use of STACK - it will crash */
// int main ( void ) {
// 	Ice				i;
// 	MateriaSource	src;
// 	src.learnMateria(&i);
// 	return (0);
// }



/* Unequip materials */
// int main ( void ) {
// 	Character		nico("Nico");
// 	MateriaSource	src;
// 	AMateria*		i = new Ice();

// 	src.learnMateria(i);
// 	AMateria* tmp = src.createMateria("ice");

// 	nico.equip(tmp);
// 	AMateria* save = nico.getItemAddress(0);
// 	nico.unequip(0);

// 	delete i;
// 	delete save;
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
// 	nico->use(4, *minishell); // fail to use

// 	AMateria* save_0 = nico->getItemAddress(0); // the object on the flood need to be saved!
// 	nico->unequip(0);
// 	AMateria* save_1 = nico->getItemAddress(1);
// 	nico->unequip(1);
// 	AMateria* save_2 = nico->getItemAddress(2);
// 	nico->unequip(2);
// 	AMateria* save_3 = nico->getItemAddress(3);
// 	nico->unequip(3);

// 	delete minishell;
// 	delete nico;
// 	delete [] ices;
// 	delete save_0;
// 	delete save_1;
// 	delete save_2;
// 	delete save_3;
// 	return (0);
// }



// int main ( void ) {
// 	Character		nico("Nico");
// 	MateriaSource	src;
// 	Ice*			ice0 = new Ice();
// 	Ice*			ice1 = new Ice();
// 	Cure*			cure0 = new Cure();
// 	Cure*			cure1 = new Cure();
// 	Ice				ice2;
// 	Ice				ice3;
// 	std::cout << std::endl;

// 	src.learnMateria(cure0);
// 	src.learnMateria(cure1);
// 	AMateria*	cure_created = src.createMateria("cure");			// will create from cure1
// 	nico.equip(cure_created);										// items[0]
// 	std::cout << std::endl;

// 	src.learnMateria(ice0);
// 	AMateria*	ice_created = src.createMateria("ice");				// will create from ice0
// 	src.learnMateria(ice1);
// 	AMateria*	another_ice = src.createMateria("ice");				// will create from ice1
// 	nico.equip(ice_created);										// items[1]
// 	nico.equip(another_ice);										// items[2]
// 	std::cout << std::endl;

// 	src.learnMateria(&ice2); std::cout << std::endl;					// not learned, but automatically freed
// 	src.learnMateria(&ice3); std::cout << std::endl << std::endl;		// not learned, but automatically freed
// 	std::cout << std::endl;

// 	std::cout << nico.getItemsAddress()[0]->getType() << std::endl;
// 	std::cout << nico.getItemsAddress()[1]->getType() << std::endl;
// 	std::cout << nico.getItemsAddress()[2]->getType() << std::endl;
// 	std::cout << std::endl;

// 	AMateria*	save_0 = nico.getItemAddress(0);
// 	nico.unequip(0);	// unequip cure_created
// 	AMateria*	save_1 = nico.getItemAddress(1);
// 	nico.unequip(1);	// unequip ice_created

// 	delete ice0;
// 	delete ice1;
// 	delete cure0;
// 	delete cure1;
// 	delete save_0;
// 	delete save_1;
// 	return (0);
// }



/* Character class tests */
// int main ( void ) {
// 	Character*	nico = new Character("nico");
// 	MateriaSource	src;
// 	Ice				i;
// 	src.learnMateria(&i);
// 	(*nico).equip(&i);

// 	Character	nico_reass;
// 	Cure		c;
// 	src.learnMateria(&c);
// 	nico_reass.equip(&c);

// 	nico_reass = (*nico); // operator=

// 	///////////////////////////
// 	Character	nico_cpy( *nico );

// 	delete nico;
// 	return (0);
// }



int main ( void ) {
	MateriaSource	src;
	MateriaSource	src_cpy ( src );
	Ice				ice;
	Cure			cure;

	src.learnMateria(&ice);
	src_cpy.learnMateria(&cure);

	src.createMateria("cure");
	src_cpy.createMateria("ice");

	Character	nico("Nic");
	Character	enemy("enemy");
	nico.use(0, enemy);
	nico.use(100, enemy);
	return (0);
}
