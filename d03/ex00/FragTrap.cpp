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
	std::cout << "Destructor called" << std::endl;
}

FragTrap::FragTrap():	_name("-"),
						_hitPoints(100),
						_maxHitPoints(100),
						_energyPoints(100),
						_maxEnergyPoints(100),
						_level(1),
						_meleeAttackDamege(30),
						_rangedAttackDamege(20),
						_armorDamageReduction(5)
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name):	_name(name),
												_hitPoints(100),
												_maxHitPoints(100),
												_energyPoints(100),
												_maxEnergyPoints(100),
												_level(1),
												_meleeAttackDamege(30),
												_rangedAttackDamege(20),
												_armorDamageReduction(5)
{
	std::cout << "Name set constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &			FragTrap::operator=(FragTrap const & ft)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name  = ft._name ;
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

void				FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " attacks " << target;
	std::cout << " range, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " attacks " << target;
	std::cout << " melee, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " : My robotic flesh get" << amount;
	this->_hitPoints = std::max(this->_hitPoints - (int)amount, 0);
	std::cout << " points of demage! AAHH! My health : " << this->_hitPoints << std::endl;
}

void				FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " : I found " << amount << " hit points! ";
	this->_hitPoints = std::min(this->_hitPoints + (int)amount, this->_maxHitPoints);
	std::cout << "My health : " << this->_hitPoints << std::endl;
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

	std::cout << "FR4G-TP " << this->_name << "vaulthunter_dot_exe :";
	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		i = rand() % 5;
		std::cout << str[i] << std::endl;
	}
	else
		std::cout << "Low Energy...." << std::endl;

}
