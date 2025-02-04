/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:17:44 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 11:17:47 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructed" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructed" << std::endl;
	this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
