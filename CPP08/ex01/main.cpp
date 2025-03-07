/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:41 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 12:46:44 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main()
{
	{
		std::cout << "subject test:" << std::endl;
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "----------------------------------" << std::endl;
		std::cout << "range test:" << std::endl;
		Span	sp = Span(10000);

		std::srand(time(NULL));
		std::vector<int>	range;
		for (int i = 0; i < 10000; i++)
			range.push_back(rand() % 100000);

		try {
			sp.addRange(range.begin(), range.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
