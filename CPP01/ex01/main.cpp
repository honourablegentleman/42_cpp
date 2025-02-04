/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:35:59 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 12:36:01 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N;

	N = 10;
	horde = zombieHorde(N, "Dave");
	for(int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
