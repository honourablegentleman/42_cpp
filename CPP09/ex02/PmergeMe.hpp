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

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe	&operator=(const PmergeMe &cpy);
	~PmergeMe();
	void				execute(char **argv);
	int					argCheck(char **argv);
	std::vector<int>	generateJacobsthal(int n);
	double				VectorInsert(std::vector<int> &vec, char **argv);
	std::vector<int>	vectorMergeSort(std::vector<int> &vec);
	std::vector<std::pair<int, int> >	vectorPair(std::vector<int> &vec);
	double				ListInsert(std::list<int> &list, char **argv);
	std::list<int>		listMerge(std::list<int> &left, std::list<int> &right);
	std::list<int>		listMergeSort(std::list<int> &list);
	class	ErrorMsg : public std::exception {
	public:
		const char	*what() const throw();
	};
};


#endif
