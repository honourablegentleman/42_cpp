/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:47:25 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 13:47:40 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T *array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
