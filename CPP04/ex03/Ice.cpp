/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:38:09 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 14:38:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
}

Ice	&Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	AMateria	*newIce = new Ice(*this);
	newIce->setHolder(NULL);
	return (newIce);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
