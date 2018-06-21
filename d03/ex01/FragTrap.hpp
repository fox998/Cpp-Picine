/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:23:18 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 16:23:21 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAGTRAP_HPP
# define	FRAGTRAP_HPP

#include	<string>

class	FragTrap
{
	protected:
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
		~FragTrap();
		FragTrap();
		FragTrap(FragTrap const & ft);
		FragTrap(std::string const & name);

		FragTrap &		operator=(FragTrap const & ft);

		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaulthunter_dot_exe(std::string const & target);
};

#endif
