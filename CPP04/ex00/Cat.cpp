/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:07 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:44:10 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructed" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructed" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
