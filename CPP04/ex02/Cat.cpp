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
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructed" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->brain->setIdea(i, idea);
}

std::string	Cat::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("");
	return (this->brain->getIdea(i));
}
