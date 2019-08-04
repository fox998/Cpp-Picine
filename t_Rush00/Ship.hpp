/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:04:08 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 15:04:10 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SHIP_HPP
# define	SHIP_HPP

#include	"Object.hpp"
#include	"Bullet.hpp"

class	Ship : public Object
{
	protected:
		int		_health;

		virtual ~Ship();
		Ship();
		Ship(Ship const & copy);

	public:
		Bullet				doShot();

		Ship &				operator=(Ship const & s);
		int					getHealth() const;
		virtual bool		collision(Object const & o);

};

#endif
