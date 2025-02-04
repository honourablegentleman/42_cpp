/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:45:03 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 12:45:07 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitpoints = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Default has been created! [Constructor called]"
			  << std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << copy.name << " has been created! [Copy constructor called]"
				<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " has been created! [Name constructor called]"
				<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed! "
				"[Destructor called]" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap &copy)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " has high fived!" << std::endl;
}
