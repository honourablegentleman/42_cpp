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
		const Animal *j = new Animal();
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		delete j;
	}
	{
		const Animal *i = new Cat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		delete i;
	}
	return (0);
}
