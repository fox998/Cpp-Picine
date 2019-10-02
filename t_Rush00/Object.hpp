/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:07:06 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:07:08 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		OBJECT_HPP
# define	OBJECT_HPP

#include	"Point.hpp"

class	Object
{
	protected:
		Point		_position;
		Point		_speed;
		int			_health;


		Object(Object const & copy);
		Object(Point const & position, Point const & speed, int health);
		Object();

		Object &			operator=(Object const & o);

	public:
		void				setHealth(int health);
		int					getHealth() const;
		virtual ~Object();

		bool				f;

		Point const &				getPosition() const;
		void						setPosition(Point const & p);
		Point const &				move();
		Point const &				move(Point const & p);

		void						drow(int color);

		virtual bool				collision(Object & o) = 0;
};

#endif

