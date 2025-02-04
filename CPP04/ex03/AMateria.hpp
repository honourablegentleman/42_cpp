/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:22:02 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/22 13:22:04 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class ICharacter;
class IMateriaSource;

class AMateria
{
protected:
	std::string		type;
	ICharacter		*holder;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	AMateria	&operator=(const AMateria &copy);
	virtual ~AMateria();
	void		setHolder(ICharacter *holder);
	std::string const	&getType() const;
	ICharacter	*getHolder() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter &target) = 0;
};

#endif
