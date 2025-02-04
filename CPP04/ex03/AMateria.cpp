/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:22:15 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 13:22:18 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default"), holder(NULL)
{
}

AMateria::AMateria(std::string const &type) : type(type), holder(NULL)
{
}

AMateria::AMateria(const AMateria &copy) : type(copy.type), holder(NULL)
{
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	this->type = copy.type;
	return (*this);
}

AMateria::~AMateria()
{
}

void	AMateria::setHolder(ICharacter *holder)
{
	this->holder = holder;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

ICharacter	*AMateria::getHolder() const
{
	return (this->holder);
}
