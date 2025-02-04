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

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	robot1;
	ScavTrap	robot("Phil");
	ScavTrap	robot2(robot);

	robot.attack("enemy");
	robot.guardGate();
	robot1.takeDamage(5);
	robot.takeDamage(9);
	robot.beRepaired(5);
	robot.guardGate();
	robot2.guardGate();
	robot2.attack("enemy");
	robot2.guardGate();
	return (0);
}
