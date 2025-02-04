/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:56 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 15:43:57 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	robot1;
	ClapTrap	robot("Phil");
	ClapTrap	robot2(robot);

	robot.attack("enemy");
	robot1.takeDamage(5);
	robot.takeDamage(9);
	robot.beRepaired(10);
	robot2.attack("enemy");
	return (0);
}
