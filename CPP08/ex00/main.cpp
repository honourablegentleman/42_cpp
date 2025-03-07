/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:00:11 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 12:00:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	{
		std::cout << "vector test:" << std::endl;
		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		try {
			std::cout << *easyfind(vec, 3) << std::endl;
			std::cout << *easyfind(vec, 6) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << *easyfind(vec, 15) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "list test:" << std::endl;
		std::list<int>	list;

		for (int i = 0; i < 15; i++)
			list.push_back(i);
		try {
			std::cout << *easyfind(list, 2) << std::endl;
			std::cout << *easyfind(list, 11) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << *easyfind(list, 20) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
