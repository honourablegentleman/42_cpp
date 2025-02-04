/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:22:23 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 14:22:28 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("Dave");
	DiamondTrap c(b);

	a.attack("target");
	b.takeDamage(10);
	b.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();
	b.whoAmI();
	c.attack("target");
	return (0);
}
