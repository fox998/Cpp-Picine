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

		Object(Object const & copy);
		Object(Point const & p);
		virtual ~Object();
		Object();

		Object &			operator=(Object const & o);

	public:

		Point const &		getPosition() const;
		void				setPosition(Point const & p);
		Point &				move();

		virtual bool		collision(Object const & o) = 0;
};

#endif

