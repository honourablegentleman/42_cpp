/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:14:01 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/18 16:14:04 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &cpy)
{
	(void)cpy;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::argCheck(char **argv)
{
	for (int i = 0; argv[i]; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (!std::isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

void	PmergeMe::execute(char **argv)
{
	std::vector<int>	vec;
	std::list<int>		list;

	if (argCheck(argv))
		throw ErrorMsg();

	std::cout << "Before: ";
	for (int i = 0; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::vector<std::pair<int, int> >	vecpair;
	double	time = FordJohnson(vec, vecpair, argv);

	std::cout << "After:  ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time << " ms" << std::endl;

	std::list<std::pair<int, int> >	listpair;
	time = FordJohnson(list, listpair, argv);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::list: " << time << " ms" << std::endl;
}

const char	*PmergeMe::ErrorMsg::what() const throw()
{
	return "Error";
}

size_t	jacobsthal(size_t n)
{
	return ((pow(2, n + 1) + pow(-1, n)) / 3);
}
