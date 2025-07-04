/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:59:27 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 11:59:42 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

class ValueNotFoundException : public std::exception
{
public:
	const char	*what() const throw() {
		return "Value not found in container";
	};
};

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator	first = std::find(container.begin(), container.end(), n);
	if (first == container.end())
		throw ValueNotFoundException();
	return (first);
}

#endif
