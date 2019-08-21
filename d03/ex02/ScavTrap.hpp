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

#include	"ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		void			_outputNameOfClass();
		
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & st);

		ScavTrap &		operator=(ScavTrap const & ft);

		void			challengeNewcomer(std::string const & target);
		
};


#endif
