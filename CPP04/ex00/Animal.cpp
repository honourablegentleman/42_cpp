/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:24 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:35:29 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal copy constructed" << std::endl;
}

Animal	&Animal::operator=(const Animal &copy)
{
	type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
