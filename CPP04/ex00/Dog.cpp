/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:00 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:40:04 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructed" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructed" << std::endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
