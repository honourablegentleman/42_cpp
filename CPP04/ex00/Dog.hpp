/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:11 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:40:16 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : virtual public Animal
{
public:
	Dog();
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &copy);
	virtual ~Dog();
	virtual void	makeSound() const;
};

#endif
