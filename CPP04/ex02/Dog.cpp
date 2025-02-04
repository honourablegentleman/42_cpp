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
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructed" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("");
	return (this->brain->getIdea(i));
}
