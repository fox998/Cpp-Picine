/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:08:34 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:08:36 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BULLET_HPP
# define	BULLET_HPP

#include	"Object.hpp"

class	Bullet : public Object
{
	protected:
		int		_damage;

	public:

		virtual ~Bullet();
		Bullet();
		Bullet(Bullet const & copy);

		Bullet &		operator=(Bullet const & s);
		virtual bool		collision(Object const & o);
};

#endif
