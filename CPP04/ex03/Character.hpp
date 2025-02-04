/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:53:47 by jhoddy            #+#    #+#             */
/*   Updated: 2024/12/12 14:53:49 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*inventory[4];
	static int	char_count;
public:
	Character();
	Character(const std::string &name);
	Character(const Character &copy);
	Character	&operator=(const Character &copy);
	~Character();
	std::string const	&getName() const;
	virtual	void		equip(AMateria* m);
	virtual	void		unequip(int idx);
	virtual	void		use(int idx, ICharacter& target);
	void				void_equip(int idx);
	static AMateria	*the_void[50];
};

#endif
