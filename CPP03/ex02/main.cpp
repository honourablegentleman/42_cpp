/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:50:33 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 12:50:35 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("dave");
	FragTrap c(b);

	a.attack("target");
	a.takeDamage(10);
	a.beRepaired(10);
	a.highFivesGuys();
	c.highFivesGuys();
	return (0);
}
