/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:22:58 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 11:22:59 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
private:
	Brain	*brain;
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat	&operator=(const WrongCat &copy);
	~WrongCat();
	void	makeSound() const;
};

#endif
