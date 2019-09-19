/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:54:58 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 19:55:00 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScavTrap.hpp"
#include	<cstdlib>
#include	<iostream>

void		ScavTrap::_outputNameOfClass()
{
	std::cout << "ScavTrap : ";
}

ScavTrap::~ScavTrap()
{
	this->_outputNameOfClass();
	std::cout << "Destructor called" << std::endl;
}

ScavTrap::ScavTrap():	ClapTrap()
{
	this->_outputNameOfClass();
	std::cout << "Default constructor called" << std::endl;
	this->_energyPoints = (50);
	this->_maxEnergyPoints = (50);
	this->_meleeAttackDamege = (20);
	this->_rangedAttackDamege = (15);
	this->_armorDamageReduction = (3);
}

ScavTrap::ScavTrap(std::string const &name):	ClapTrap(name)
{
	this->_energyPoints = (50);
	this->_maxEnergyPoints = (50);
	this->_meleeAttackDamege = (20);
	this->_rangedAttackDamege = (15);
	this->_armorDamageReduction = (3);
	this->_outputNameOfClass();
	std::cout << "Name set constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy): ClapTrap(copy)
{
	this->_outputNameOfClass();
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap &			ScavTrap::operator=(ScavTrap const & ft)
{
	this->_outputNameOfClass();
	std::cout << "Assignation operator called" << std::endl;
	this->_name  = ft._name;
	this->_hitPoints = ft._hitPoints;
	this->_maxHitPoints = ft._maxHitPoints;
	this->_energyPoints = ft._energyPoints;
	this->_maxEnergyPoints = ft._maxEnergyPoints;
	this->_level = ft._level;
	this->_meleeAttackDamege = ft._meleeAttackDamege;
	this->_rangedAttackDamege = ft._rangedAttackDamege;
	this->_armorDamageReduction = ft._armorDamageReduction;
	return (*this);
}


void			ScavTrap::challengeNewcomer(std::string const & target)
{
	int i;
	std::string		str[] = 
	{
		"So, it's a draw, eh?",
		"Until we meet again on the battlefield, friendo!",
		"What? No way, I totally had you!",
		"Wow, who say that coming?",
		"Yay! We both win!"
	};

	std::cout << this->_name;
	std::cout << " attacks " << target << " by challengeNewcomer :";
	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		i = rand() % 5;
		std::cout << str[i] << std::endl;
	}
	else
		std::cout << "Low Energy...." << std::endl;
}
