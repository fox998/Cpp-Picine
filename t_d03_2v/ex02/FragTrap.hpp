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

#include	"ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:
		void			_outputNameOfClass();

	public:
		~FragTrap();
		FragTrap();
		FragTrap(FragTrap const & ft);
		FragTrap(std::string const & name);

		FragTrap &		operator=(FragTrap const & ft);
		
		void			vaulthunter_dot_exe(std::string const & target);
};

#endif
