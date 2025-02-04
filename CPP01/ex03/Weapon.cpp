/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:41 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 13:47:42 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "fists";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
