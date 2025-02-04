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

int	main(void)
{
	Harl	harl;

	std::cout << "DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << "INVALID:" << std::endl;
	harl.complain("INVALID");
	return (0);
}
