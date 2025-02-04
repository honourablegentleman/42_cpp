/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:23:32 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/08 14:23:34 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
