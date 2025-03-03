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

std::vector<int>	PmergeMe::generateJacobsthal(int n)
{
	std::vector<int>	jacob;
	if (n > 0)
		jacob.push_back(0);
	if (n > 1)
		jacob.push_back(1);

	for (int i = 2; i < n; i++) {
		int	j = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(j);
	}
	return (jacob);
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

std::vector<int>	PmergeMe::vectorMergeSort(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return (vec);

	std::vector<std::pair<int, int> >	pair = vectorPair(vec);

	std::vector<int>	main;
	std::vector<int>	pend;
	for (size_t i = 0; i < pair.size(); i++) {
		main.push_back(pair[i].first);
		if (pair[i].second != -1)
			pend.push_back(pair[i].second);
	}

	main = vectorMergeSort(main);

	std::vector<int>	jacob = generateJacobsthal(pend.size());
	for (size_t i = 0; i < pend.size(); i++) {
		size_t	index = (i < jacob.size()) ? jacob[i] : i;
		if (index < pend.size()) {
			std::vector<int>::iterator	it = std::lower_bound(main.begin(), main.end(), pend[index]);
			main.insert(it, pend[index]);
		}
	}

	return (main);
}


double	PmergeMe::VectorInsert(std::vector<int> &vec, char **argv)
{
	for (int i = 0; argv[i]; i++)
		vec.push_back(atoi(argv[i]));

	clock_t	start = clock();
	vec = vectorMergeSort(vec);
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
	for (std::vector<int>::size_type i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time << " ms" << std::endl;

	time = ListInsert(list, argv);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::list: " << time << " ms" << std::endl;
}

const char	*PmergeMe::ErrorMsg::what() const throw()
{
	return "Error";
}
