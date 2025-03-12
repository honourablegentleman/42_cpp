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

int	PmergeMe::generateJacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);

	return (generateJacobsthal(n - 1) + 2 * generateJacobsthal(n - 2));
}

std::vector<std::pair<int, int> >	PmergeMe::vectorPair(std::vector<int> &vec)
{
	std::vector<std::pair<int, int> >	res;

	for (size_t i = 0; i < vec.size() - 1; i += 2) {
		if (vec[i] < vec[i + 1])
			res.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			res.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	if (vec.size() % 2 != 0)
		res.push_back(std::make_pair(vec.back(), -1));

	return (res);
}

// test:	11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

void	PmergeMe::vectorMergeSort(std::vector<int> &vec, int lvl)
{
	int pairs = vec.size() / lvl;
	if (pairs < 2)
		return;

	bool odd = (pairs % 2 != 0);

	std::vector<int>::iterator start = vec.begin();
//	std::vector<int>::iterator	last = vec.end();
	std::vector<int>::iterator end = vec.end() - (odd * lvl);

	for (std::vector<int>::iterator it = start; it != end; std::advance(it, 2 * lvl)) {
		if (std::distance(it, end) < 2 * lvl)
			break;
		std::vector<int>::iterator curr_pair = it + (lvl - 1);
		std::vector<int>::iterator next_pair = it + ((2 * lvl) - 1);
		if (curr_pair < vec.end() && next_pair < vec.end() && *next_pair < *curr_pair) {
			std::vector<int>::iterator i_start = curr_pair - (lvl - 1);
			std::vector<int>::iterator i_end = i_start + lvl;
			for (; i_start != i_end; i_start++)
				std::iter_swap(i_start, i_start + lvl);
		}
	}

	vectorMergeSort(vec, lvl * 2);

	std::vector<std::vector<int>::iterator> main;
	std::vector<std::vector<int>::iterator> pend;

	main.push_back(start + (lvl - 1));
	main.push_back(start + ((lvl * 2) - 1));

	for (int i = 4; i <= pairs; i += 2) {
		pend.push_back(start + (lvl * (i - 1) - 1));
		main.push_back(start + (lvl * i - 1));
	}
	if (odd)
		pend.push_back(end + (lvl - 1));
}

double	PmergeMe::VectorInsert(std::vector<int> &vec, char **argv)
{
	for (int i = 0; argv[i]; i++)
		vec.push_back(atoi(argv[i]));

	clock_t	start = clock();
	vectorMergeSort(vec, 1);
	clock_t	end = clock();

	return (static_cast<double>(end - start) / 1000);
}

std::list<int>	PmergeMe::listMerge(std::list<int> &left, std::list<int> &right)
{
	std::list<int>				res;
	std::list<int>::iterator	left_it = left.begin();
	std::list<int>::iterator	right_it = right.begin();

	while(left_it != left.end() && right_it != right.end()) {
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

std::list<int>	PmergeMe::listMergeSort(std::list<int> &list)
{
	if (list.size() <= 1)
		return (list);
	std::list<int>	left;
	std::list<int>	right;

	std::list<int>::iterator	it = list.begin();
	std::advance(it, list.size() / 2);

	left.splice(left.begin(), list, list.begin(), it);
	right.splice(right.begin(), list, list.begin(), list.end());

	left = listMergeSort(left);
	right = listMergeSort(right);
	list = listMerge(left, right);

	return (list);
}

double	PmergeMe::ListInsert(std::list<int> &list, char **argv)
{
	for (int i = 0; argv[i]; i++)
		list.push_back(atoi(argv[i]));

	clock_t	start = clock();
	listMergeSort(list);
	clock_t	end = clock();

	return (static_cast<double>(end - start) / 1000);
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

	double	time = VectorInsert(vec, argv);

	std::cout << "After:  ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time << " ms" << std::endl;

	time = ListInsert(list, argv);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::list: " << time << " ms" << std::endl;
}

const char	*PmergeMe::ErrorMsg::what() const throw()
{
	return "Error";
}
