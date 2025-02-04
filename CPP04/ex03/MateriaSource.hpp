/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:47:11 by jhoddy            #+#    #+#             */
/*   Updated: 2024/12/13 11:47:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource	&operator=(const MateriaSource &copy);
	~MateriaSource();
	virtual	void		learnMateria(AMateria*);
	virtual	AMateria*	createMateria(std::string const & type);
};

#endif
