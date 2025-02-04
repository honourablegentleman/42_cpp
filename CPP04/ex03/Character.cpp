/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:53:37 by jhoddy            #+#    #+#             */
/*   Updated: 2024/12/12 14:53:40 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int	Character::char_count = 0;

AMateria	*Character::the_void[50] = {NULL};

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->char_count++;
}

Character::Character(const std::string &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->char_count++;
}

Character::Character(const Character &copy) : name(copy.name)
{
	this->char_count++;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
		{
			this->inventory[i] = copy.inventory[i]->clone();
			this->inventory[i]->setHolder(this);
		}
		else
			this->inventory[i] = NULL;
	}
}

Character	&Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
			{
				this->inventory[i] = copy.inventory[i]->clone();
				this->inventory[i]->setHolder(this);
			}
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	this->char_count--;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	if (this->char_count == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			if (Character::the_void[i])
			{
				delete Character::the_void[i];
				Character::the_void[i] = NULL;
			}
		}
	}
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (m->getHolder())
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			m->setHolder(this);
			return ;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		if (Character::the_void[i] == NULL)
		{
			Character::the_void[i] = m;
			Character::the_void[i]->setHolder(NULL);
			return ;
		}
	}
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return ;
	for (int i = 0; i < 50; i++)
	{
		if (Character::the_void[i] == NULL)
		{
			Character::the_void[i] = this->inventory[idx];
			Character::the_void[i]->setHolder(NULL);
			this->inventory[idx] = NULL;
			return ;
		}
	}
}

void	Character::void_equip(int idx)
{
	if (idx < 0 || idx >= 50 || Character::the_void[idx] == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = Character::the_void[idx];
			this->inventory[i]->setHolder(this);
			Character::the_void[idx] = NULL;
			return ;
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx]->use(target);
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}
