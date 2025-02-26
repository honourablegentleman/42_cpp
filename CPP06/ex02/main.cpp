/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:11:16 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 12:11:20 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int		random = std::rand() % 3;

	if (random == 0) {
		std::cout << "A class created" << std::endl;
		return (new A);
	}
	else if (random == 1) {
		std::cout << "B class created" << std::endl;
		return (new B);
	}
	else {
		std::cout << "C class created" << std::endl;
		return (new C);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "Unknown class" << std::endl;
			}
		}
	}
}

int	main()
{
	Base	*base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
