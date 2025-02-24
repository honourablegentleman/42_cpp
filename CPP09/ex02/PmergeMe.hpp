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
	void	execute(char **argv);
	void	VectorInsert(char **argv);
	void	merge(std::vector<int> &vec, int left, int mid, int right);
	void	mergeSort(std::vector<int> &vec, int left, int right);
	class	ErrorMsg : public std::exception {
	public:
		const char	*what() const throw();
	};
};


#endif
