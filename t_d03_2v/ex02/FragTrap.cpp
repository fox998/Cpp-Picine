/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:23:10 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 16:23:12 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"
#include	<iostream>
#include	<cstdlib>

FragTrap::~FragTrap()
{
	this->_outputNameOfClass();
	std::cout << "Destructor called" << std::endl;
}

FragTrap::FragTrap():	ClapTrap()
{
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_meleeAttackDamege = 30;
	this->_rangedAttackDamege = 20;
	this->_armorDamageReduction = 5;
	this->_outputNameOfClass();
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name):	ClapTrap(name)
{
	this->_energyPoints = (100);
	this->_maxEnergyPoints = (100);
	this->_meleeAttackDamege = (30);
	this->_rangedAttackDamege = (20);
	this->_armorDamageReduction = (5);
	this->_outputNameOfClass();
	std::cout << "Name set constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy)
{
	this->_outputNameOfClass();
	std::cout << "Copy constructor called" << std::endl;
}

void				FragTrap::_outputNameOfClass()
{
	std::cout << "FragTrap :";
}

FragTrap &			FragTrap::operator=(FragTrap const & ft)
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

void				FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int i;
	std::string		str[] = 
	{
		"Just point me in the right direction!",
		"Here I come to save the day!",
		"So uh...great weather we're having.",
		"Ooh yeah, watch me! Watch me go!",
		"Have no fear, mini-trap is here!"
	};

	std::cout << this->_name;
	std::cout << " attacks " << target << " by vaulthunter_dot_exe : ";
	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		i = rand() % 5;
		std::cout << str[i] << std::endl;
	}
	else
		std::cout << "Low Energy...." << std::endl;

}
