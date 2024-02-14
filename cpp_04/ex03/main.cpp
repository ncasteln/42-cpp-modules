/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:11 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/14 15:40:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/* Reassignment operator AMateria */
int main ( void ) {
	Ice			i;
	Cure		c;
	AMateria	*pi = &i;
	AMateria	*pc = &c;

	*pi = *pc;
	return (0);
}



/* Subject test */
// int main ( void ) {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
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
// 	return (0);
// }



/* Other tests */
// int main ( void ) {
// 	Character		nico("Nico");
// 	Character		nico_clone("Nico the clone");

// 	Character*		heap_enemy = new Character("enemy");
// 	Character*		heap_enemy_clone( heap_enemy );

// 	MateriaSource*	heap_src = new MateriaSource();

// 	AMateria*		heap_ice = new Ice();
// 	AMateria*		heap_cure = new Cure();
// 	Ice				stack_ice;
// 	Cure			stack_cure;

// 	AMateria		*tmp;
// 	std::cout << std::endl;

// 	heap_src->learnMateria(heap_ice);
// 	heap_src->learnMateria(heap_cure);
// 	heap_src->learnMateria(&stack_ice);
// 	heap_src->learnMateria(&stack_cure);
// 	std::cout << std::endl;

// 	tmp = heap_src->createMateria("ice");	// which materia returns ?
// 	nico.equip(tmp);
// 	nico.equip(tmp);						// not requested
// 	nico.equip(NULL);
// 	std::cout << std::endl;

// 	nico.use(0, *heap_enemy);
// 	nico.use(1, *heap_enemy_clone);
// 	nico.use(2, *heap_enemy);
// 	nico.use(3, *heap_enemy_clone);
// 	nico.use(99, *heap_enemy_clone);
// 	std::cout << std::endl;

// 	nico.unequip(0);
// 	nico.unequip(1);
// 	nico.unequip(2);
// 	nico.unequip(3);
// 	nico.unequip(99);
// 	std::cout << std::endl;

// 	delete heap_enemy;
// 	delete heap_src;
// 	delete heap_ice;
// 	delete heap_cure;
// 	return (0);
// }



/* Complete STACK tests */
// int main ( void ) {
// 	Character		nico("Nico");
// 	Character		enemy("enemy");
// 	MateriaSource	src;
// 	Ice				ice_stack;
// 	AMateria*		m;

// 	std::cout << std::endl;

// 	src.learnMateria(&ice_stack);		// store address
// 	std::cout << std::endl;

// 	m = src.createMateria("ice");		// clone
// 	nico.equip(m);
// 	std::cout << std::endl;

// 	nico.use(0, enemy);
// 	std::cout << std::endl;

// 	nico.unequip(0);
// 	std::cout << std::endl;

// 	return (0);
// }



/* Character class with AMateria tests */
// int main ( void ) {
// 	ICharacter	*nico = new Character("Nico");
// 	AMateria	*ice_heap = new Ice();
// 	Ice			ice_stack;

// 	nico->equip(ice_heap);
// 	nico->equip(&ice_stack);

// 	delete nico;
// 	delete ice_heap;
// 	return (0);
// }


/* Complete HEAP tests */
// int main ( void ) {
// 	ICharacter		*nico = new Character("Nico");
// 	ICharacter		*enemy = new Character("enemy");
// 	IMateriaSource	*src = new MateriaSource();
// 	AMateria		*m;
// 	std::cout << std::endl;

// 	src->learnMateria(new Ice());		// store address
// 	std::cout << std::endl;

// 	m = src->createMateria("ice");		// clone
// 	nico->equip(m);
// 	std::cout << std::endl;

// 	nico->use(0, *enemy);
// 	std::cout << std::endl;

// 	nico->unequip(0);
// 	std::cout << std::endl;

// 	delete enemy;
// 	delete src;
// 	delete nico;
// 	delete m;
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
// 	std::cout << "nico_to_reassign _item address -> " << nico_to_reassign.getItemsAddress() << std::endl;

// 	nico.unequip(0);
// 	nico.use(0, enemy);				// the slot is empty
// 	nico_to_reassign.use(0, enemy);	// the slot is not empty, therefore can use it

// 	delete i0;
// 	return (0);
// }
