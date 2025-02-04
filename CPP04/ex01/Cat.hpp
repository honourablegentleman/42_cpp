/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:43:38 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 10:43:40 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CAT_HPP
# define CPP04_CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &copy);
	virtual ~Cat();
	virtual void	makeSound() const;
	void			setIdea(int i, std::string idea);
	std::string		getIdea(int i) const;
};

#endif
