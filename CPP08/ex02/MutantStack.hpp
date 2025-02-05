/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:36:46 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 13:36:55 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &cpy);
	MutantStack<T>	&operator=(const MutantStack &cpy);
	~MutantStack();
	typedef typename std::stack<T>::container_type::iterator	iterator;
	iterator begin();
	iterator end();
};

#endif
