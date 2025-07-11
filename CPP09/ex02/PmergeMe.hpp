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

size_t	jacobsthal(size_t n);

template <typename Pair>
void	Merge(Pair &pair, Pair &left, Pair &right)
{
	pair.clear();
	typename Pair::iterator	left_it = left.begin();
	typename Pair::iterator	right_it = right.begin();

	while (left_it != left.end() && right_it != right.end()) {
		if (left_it->second < right_it->second) {
			pair.push_back(*left_it);
			left_it++;
		}
		else {
			pair.push_back(*right_it);
			right_it++;
		}
	}

	while (left_it != left.end()) {
		pair.push_back(*left_it);
		left_it++;
	}
	while (right_it != right.end()) {
		pair.push_back(*right_it);
		right_it++;
	}

}

template <typename Pair>
void	MergeSort(Pair &pair, int n)
{
	if (n < 2)
		return ;

	int	leftmid = n / 2;
	int	rightmid = n - leftmid;
	Pair	left;
	Pair	right;

	typename Pair::iterator it = pair.begin();
	for (int i = 0; i < leftmid; i++) {
		left.push_back(*it);
		it++;
	}
	for (int i = 0; i < rightmid; i++) {
		right.push_back(*it);
		it++;
	}

	MergeSort(left, leftmid);
	MergeSort(right, rightmid);

	Merge(pair, left, right);
}

template <typename Container, typename Pair>
void	MakePair(Container &con, Pair &pair)
{
	for (typename Container::iterator it = con.begin(); it != con.end(); std::advance(it, 2)) {
		typename Container::iterator	next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
		if (*it > *next)
			pair.push_back(std::make_pair(*next, *it));
		else
			pair.push_back(std::make_pair(*it, *next));
	}
}

template <typename Iterator>
Iterator	BinarySearch(Iterator first, Iterator last, int value)
{
	Iterator	it;
	int			count = std::distance(first, last);
	int			step = 0;

	while (count > 0) {
		it = first;
		step = count / 2;
		std::advance(it, step);
		if (value >= *it) {
			first = ++it;
			count -= step + 1;
		}
		else
			count = step;
	}
	return (first);
}

template <typename Container>
void	BetweenJacobsthal(Container &res, Container low, Container high, int left, int right)
{
	typename Container::iterator	left_it;
	typename Container::iterator	right_it;
	while (left < right) {
		left_it = res.begin();
		right_it = res.begin();

		typename Container::iterator	high_it = high.begin();
		std::advance(high_it, right);
		int	high_val = *high_it;

		while (*right_it != high_val)
			right_it++;

		typename Container::iterator low_it = low.begin();
		std::advance(low_it, right);
		int low_val = *low_it;

		res.insert(BinarySearch(left_it, right_it, low_val), low_val);
		right--;
	}
}

template <typename Container>
void	Insertion(Container &con, Container low, Container high)
{
	con = high;
	if (!low.empty())
		con.insert(con.begin(), low.front());
	size_t	i = 0;
	while (jacobsthal(i + 1) <= high.size()) {
		BetweenJacobsthal(con, low, high, jacobsthal(i) - 1, jacobsthal(i + 1) - 1);
		i++;
	}
	BetweenJacobsthal(con, low, high, jacobsthal(i) - 1, high.size() - 1);
	if (low.size() > high.size()) {
		typename Container::iterator	con_it = --con.end();
		typename Container::iterator	low_it = --low.end();
		con.insert(BinarySearch(con.begin(), con_it, *low_it), *low_it);
	}
}

template <typename Container, typename Pair>
void	InsertAndSort(Container &con, Pair &pair)
{
	MakePair(con, pair);
	MergeSort(pair, pair.size());
	Container	high;
	Container	low;
	for (typename Pair::iterator it = pair.begin(); it != pair.end(); it++) {
		high.push_back(it->second);
		low.push_back(it->first);
	}
	if (con.size() % 2)
		low.push_back(con.back());

	Insertion(con, low, high);
}

template <typename Container, typename Pair>
double	FordJohnson(Container &con, Pair &pair, char **argv)
{
	for (int i = 0; argv[i]; i++)
		con.push_back(std::atoi(argv[i]));

	clock_t	start = clock();
	InsertAndSort(con, pair);
	clock_t	end = clock();

	return (static_cast<double>(end - start) / 1000);
}

#endif
