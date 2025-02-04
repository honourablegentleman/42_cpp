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
# include "Brain.hpp"

class Dog : virtual public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &copy);
	virtual ~Dog();
	virtual void	makeSound() const;
	void			setIdea(int i, std::string idea);
	std::string		getIdea(int i) const;
};

#endif
