/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:12:10 by jhoddy            #+#    #+#             */
/*   Updated: 2024/10/15 12:12:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::add_contact(Contact& contact)
{
	contacts[this->index] = contact;
	contacts[this->index].set_index(this->index + 1);
	this->index = (this->index + 1) % 8;
	if (max_index < 8)
		max_index++;
}

int	Phonebook::get_max_index()
{
	return (max_index);
}

Contact	*Phonebook::get_contacts(int index)
{
	return (&contacts[index]);
}
