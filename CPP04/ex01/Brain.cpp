/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:33:33 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 11:33:39 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructed" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}
