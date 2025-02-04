/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:32:44 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 11:32:48 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data	data;
	data.s1 = "Very";
	data.n = 13;
	data.s2 = "True";

	uintptr_t	raw = Serializer::serialize(&data);
	Data		*ptr = Serializer::deserialize(raw);

	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;

	return (0);
}
