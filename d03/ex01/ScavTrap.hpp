/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:55:06 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 19:55:08 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

class	ScavTrap
{
	private:
		std::string		_name;
		int				_hitPoints;
		int				_maxHitPoints;
		int				_energyPoints;
		int				_maxEnergyPoints;
		int				_level;
		int				_meleeAttackDamege;
		int				_rangedAttackDamege;
		int				_armorDamageReduction;
	
		void			_outputNameOfClass();
		
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & st);

		ScavTrap &		operator=(ScavTrap const & ft);

		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			challengeNewcomer(std::string const & target);
		
};


#endif
