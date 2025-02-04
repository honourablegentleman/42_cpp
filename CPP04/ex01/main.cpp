/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:34:24 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:34:26 by jhoddy           ###   ########.fr       */
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
		const Animal* meta[10];

		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << meta[i]->getType() << ": ";
			meta[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete meta[i];
	}
	{
		std::cout << "---------------------" << std::endl;
		Cat *a = new Cat();
		a->setIdea(0, "I am a cat");
		a->setIdea(1, "Very True");
		std::cout << "\nIdea 1: " << a->getIdea(0) << std::endl;
		std::cout << "Idea 2: " << a->getIdea(1) << std::endl;
		std::cout << std::endl;
		delete a;
	}
	{
		std::cout << "---------------------" << std::endl;
		Cat *b = new Cat();
		Cat *c = new Cat();
		b->setIdea(0, "I am a cat");
		b->setIdea(1, "Very True");
		*c = *b;
		std::cout << "\nIdea 1: " << c->getIdea(0) << std::endl;
		std::cout << "Idea 2: " << c->getIdea(1) << std::endl;
		std::cout << std::endl;
		Cat *d = new Cat(*b);
		std::cout << "\nIdea 1: " << d->getIdea(0) << std::endl;
		std::cout << "Idea 2: " << d->getIdea(1) << std::endl;
		std::cout << std::endl;
		delete b;
		delete c;
		delete d;
	}
	return (0);
}
