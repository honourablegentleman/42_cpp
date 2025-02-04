/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:09:58 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 14:10:02 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name")
{
	this->name = "Default";
	this->hitpoints = FragTrap::hitpoints;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap Default has been created! [Constructor called]"
				<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hitpoints = FragTrap::hitpoints;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name
			  << " has been created! [Name constructor called]" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy),
FragTrap(copy)
{
	this->name = copy.name;
	std::cout << "DiamondTrap " << copy.name
				<< " has been created! [Copy constructor called]" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name
				<< " has been destroyed! [Destructor called]" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &copy)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << " and my ClapTrap name is "
				<< ClapTrap::name << std::endl;
}
