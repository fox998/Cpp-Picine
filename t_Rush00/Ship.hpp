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
		Ship();
		Ship(Ship const & copy);
		Ship(Point const & position, Point const & speed, int health);

	public:
		virtual ~Ship();
		Bullet				doShot(Point const & speed);

		Ship &				operator=(Ship const & s);
		virtual bool		collision(Object & o);

};

#endif
