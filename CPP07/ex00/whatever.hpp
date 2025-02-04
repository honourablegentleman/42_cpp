/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:35:03 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 13:35:19 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>

void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>

T	min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>

T	max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}


#endif
