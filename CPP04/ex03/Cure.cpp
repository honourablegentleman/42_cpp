/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:40:05 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 14:40:07 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
}

Cure	&Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	AMateria	*newCure = new Cure(*this);
	newCure->setHolder(NULL);
	return (newCure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
