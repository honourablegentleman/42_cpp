/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:39:59 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 14:40:00 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	Cure	&operator=(const Cure &copy);
	virtual ~Cure();
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter &target);
};

#endif
