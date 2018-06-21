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

#include	"FragTrap.hpp"

class	ScavTrap : public FragTrap
{
	private:
		void			_outputNameOfClass();
		
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & st);
		
};


#endif
