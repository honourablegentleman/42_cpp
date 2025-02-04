/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:21:11 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 13:21:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

int main()
{
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter	*dave = new Character("Dave");

		for (int i = 0; i < 55; i++)
			dave->equip(src->createMateria("ice"));

		dave->unequip(0);
		delete dave;
		delete src;
	}
	{
		std::cout << "--------------------------------" << std::endl;
		IMateriaSource *src = new MateriaSource();
		AMateria *materia = new Ice();
		src->learnMateria(materia);
		AMateria *materia2 = src->createMateria("ice");
		Character *dave = new Character("Dave");
		dave->equip(materia2);
		Character *phil = new Character(*dave);
		phil->use(0, *dave);
		phil->use(0, *dave);
		Character *bob = new Character("Bob");
		dave->unequip(0);
		bob->void_equip(0);
		*bob = *phil;
		bob->use(0, *dave);
		delete dave;
		delete phil;
		delete bob;
		delete src;
	}

	return 0;
}
