/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:06 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:35:08 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &copy);
	Animal	&operator=(const Animal &copy);
	std::string	getType() const;
	virtual ~Animal();
	virtual void	makeSound() const;
};

#endif
