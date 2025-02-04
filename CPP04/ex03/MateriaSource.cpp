/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:46:58 by jhoddy            #+#    #+#             */
/*   Updated: 2024/12/13 11:47:02 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (NULL);
}
