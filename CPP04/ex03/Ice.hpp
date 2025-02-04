/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:38:02 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 14:38:04 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &copy);
	Ice	&operator=(const Ice &copy);
	virtual ~Ice();
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter &target);
};

#endif
