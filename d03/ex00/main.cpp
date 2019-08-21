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

int		main()
{
	FragTrap	f1;
	FragTrap	f2("f2");
	FragTrap	f3(f1);

	f2.meleeAttack("target 1");
	f2.rangedAttack("target 2");
	f2.vaulthunter_dot_exe("target 3");
	f2.takeDamage(20);
	f2.beRepaired(25);

	f1 = f2;
}
