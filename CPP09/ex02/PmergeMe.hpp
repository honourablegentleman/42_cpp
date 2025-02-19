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
#include <vector>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe	&operator=(const PmergeMe &cpy);
	~PmergeMe();
	void	execute(char **argv);
	void	VectorInsert(char **argv);
	class	ErrorMsg : public std::exception {
	public:
		const char	*what() const throw();
	};
};


#endif
