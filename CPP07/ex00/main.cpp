/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:27:15 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 13:27:16 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::vector<int>	e;
	e.push_back(3);
	e.push_back(4);
	std::vector<int>	f;
	f.push_back(7);
	f.push_back(6);

	::swap(e, f);
	std::cout << "e = ";
	for (size_t i = 0; i < e.size(); i++)
		std::cout << e[i] << " ";
	std::cout << ", f = ";
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i]<< " ";
	std::cout << std::endl;
	std::cout << "min( e, f ) = ";
	for (size_t i = 0; i < e.size(); i++)
		std::cout << ::min( e, f )[i] << " ";
	std::cout << std::endl;
	std::cout << "max( e, f ) = ";
	for (size_t i = 0; i < e.size(); i++)
		std::cout << ::max( e, f )[i] << " ";
	std::cout << std::endl;

	return 0;
}
