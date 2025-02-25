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

std::vector<int>	PmergeMe::vectorMerge(std::vector<int> &left, std::vector<int> &right)
{
	std::vector<int>				res;
	std::vector<int>::iterator	left_it = left.begin();
	std::vector<int>::iterator	right_it = right.begin();

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

std::vector<int>	PmergeMe::vectorMergeSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return (vec);

	std::vector<int>::iterator	mid = vec.begin();
	std::advance(mid, vec.size() / 2);

	std::vector<int>	left(vec.begin(), mid);
	std::vector<int>	right(mid, vec.end());

	left = vectorMergeSort(left);
	right = vectorMergeSort(right);

	vec = vectorMerge(left, right);
	return (vec);
}

double	PmergeMe::VectorInsert(std::vector<int> &vec, char **argv)
{
	for (int i = 0; argv[i]; i++)
		vec.push_back(atoi(argv[i]));

	clock_t	start = clock();
	vectorMergeSort(vec);
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

void	PmergeMe::execute(char **argv)
{
	std::vector<int>	vec;
	std::list<int>		list;

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
