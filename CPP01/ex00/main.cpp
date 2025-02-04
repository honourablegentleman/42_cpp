/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:31:56 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 11:31:58 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zombie;

	zombie = newZombie("Dave");
	zombie->announce();
	randomChump("John");
	delete zombie;
	return (0);
}
