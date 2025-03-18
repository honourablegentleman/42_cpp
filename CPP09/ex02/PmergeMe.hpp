/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:14:16 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/18 16:14:32 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <algorithm>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe	&operator=(const PmergeMe &cpy);
	~PmergeMe();
	void	execute(char **argv);
	int		argCheck(char **argv);
	class	ErrorMsg : public std::exception {
	public:
		const char	*what() const throw();
	};
};

template <typename Container>
Container	Merge(Container &left, Container &right)
{
	Container						res;
	typename Container::iterator	left_it = left.begin();
	typename Container::iterator	right_it = right.begin();

	while (left_it != left.end() && right_it != right.end()) {
		if (*left_it <= *right_it) {
			res.push_back(*left_it);
			left_it++;
		}
		else {
			res.push_back(*right_it);
			right_it++;
		}
	}

	res.insert(res.end(), left_it, left.end());
	res.insert(res.end(), right_it, right.end());

	return (res);
}

template <typename Container>
Container	MergeSort(Container &con)
{
	if (con.size() <= 1)
		return (con);

	typename Container::iterator	mid = con.begin();
	std::advance(mid, con.size() / 2);

	Container	left(con.begin(), mid);
	Container	right(mid, con.end());

	left = MergeSort(left);
	right = MergeSort(right);

	con = Merge(left, right);
	return (con);
}

template <typename Container>
double	InsertAndSort(Container &con, char **argv)
{
	for (int i = 0; argv[i]; i++)
		con.push_back(std::atoi(argv[i]));

	clock_t	start = clock();
	MergeSort(con);
	clock_t	end = clock();

	return (static_cast<double>(end - start) / 1000);
}

#endif
