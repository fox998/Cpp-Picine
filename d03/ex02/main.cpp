/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:23:31 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 16:23:33 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"
#include	"ScavTrap.hpp"
#include	<iostream>

int		main()
{
	{
		std::cout << std::endl << "FragTrap Constructors" << std::endl;
		FragTrap	f1;
		FragTrap	f2("f2");
		FragTrap	f3(f1);

		std::cout << std::endl << "FragTrap Member Funck" << std::endl;
		f2.meleeAttack("target 1");
		f2.rangedAttack("target 2");
		f2.vaulthunter_dot_exe("target 3");
		f2.takeDamage(20);
		f2.beRepaired(25);
		f1 = f2;

		std::cout << std::endl << "FragTrap Destructors" << std::endl;
	}

	{
		std::cout << std::endl << "ScavTrap Constructors" << std::endl;
		ScavTrap	s1;
		ScavTrap	s2("s2");
		ScavTrap	s3(s1);

		std::cout << std::endl << "ScavTrap Member Funck" << std::endl;
		s2.meleeAttack("target 1");
		s2.rangedAttack("target 2");
		s2.challengeNewcomer("target 3");
		s2.takeDamage(20);
		s2.beRepaired(25);
		s1 = s2;

		std::cout << std::endl << "ScavTrap Destructors" << std::endl;
	}
}
