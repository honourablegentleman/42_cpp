/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:23:06 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 11:23:09 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructed" << std::endl;
	this->type = "WrongCat";
	this->brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructed" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
	delete this->brain;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}
