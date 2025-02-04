/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:34:24 by jhoddy            #+#    #+#             */
/*   Updated: 2024/12/17 12:43:07 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	{
		std::cout << "---------------------" << std::endl;
		const Cat *c = new Cat();
		const Dog *d = new Dog();

		std::cout << c->getType() << " " << std::endl;
		std::cout << d->getType() << " " << std::endl;
		c->makeSound();
		d->makeSound();
		delete c;
		delete d;
	}
	{
		std::cout << "---------------------" << std::endl;
		const WrongAnimal *w = new WrongAnimal();
		const WrongAnimal *k = new WrongCat();
		std::cout << w->getType() << " " << std::endl;
		std::cout << k->getType() << " " << std::endl;
		w->makeSound();
		k->makeSound();
		delete w;
		delete k;
	}
	return (0);
}
