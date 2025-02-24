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

void	PmergeMe::merge(std::vector<int> &vec, int left, int mid, int right)
{
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::vector<int>	vec_a(n1);
	std::vector<int>	vec_b(n2);
	for(int i = 0; i < n1; i++)
		vec_a[i] = vec[left + i];
	for(int i = 0; i < n2; i++)
		vec_b[i] = vec[mid + 1 + i];

	int i = 0;
	int	j = 0;
	int	k = left;
	while (i < n1 && j < n2) {
		if (vec_a[i] <= vec_b[j])
			vec[k] = vec_a[i++];
		else
			vec[k] = vec_b[j++];
		k++;
	}
	while (i < n1)
		vec[k++] = vec_a[i++];
	while (j < n2)
		vec[k++] = vec_b[j++];
}

void	PmergeMe::mergeSort(std::vector<int> &vec, int left, int right)
{
	if (left < right) {
		int	mid = left + (right - left) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void	PmergeMe::VectorInsert(char **argv)
{
	std::vector<int>	vec;
	for (int i = 0; argv[i]; i++)
		vec.push_back(atoi(argv[i]));

	clock_t	start = clock();
	mergeSort(vec, 0 , vec.size() - 1);
	clock_t	end = clock();

	double	time = static_cast<double>(end - start) / 1000;

	std::cout << "After:  ";
	for (std::vector<int>::size_type i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time << " ms" << std::endl;
}

void	PmergeMe::ListInsert(char **argv)
{
	std::list<int>	list;
	for (int i = 0; argv[i]; i++)
		list.push_back(atoi(argv[i]));
}

void	PmergeMe::execute(char **argv)
{
	std::cout << "Before: ";
	for (int i = 0; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	VectorInsert(argv);
	ListInsert(argv);
}

const char	*PmergeMe::ErrorMsg::what() const throw()
{
	return "Error";
}
