/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:46:21 by afokin            #+#    #+#             */
/*   Updated: 2018/06/20 15:46:23 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int						_fpval;
		static const int		_numOfFractBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();

		Fixed		&operator=(Fixed const &copy);

		bool		operator>(Fixed const &fp);
		bool		operator<(Fixed const &fp);
		bool		operator>=(Fixed const &fp);
		bool		operator<=(Fixed const &fp);
		bool		operator==(Fixed const &fp);
		bool		operator!=(Fixed const &fp);

		Fixed		operator+(Fixed const &fp);
		Fixed		operator-(Fixed const &fp);
		Fixed		operator*(Fixed const &fp);
		Fixed		operator/(Fixed const &fp);

		Fixed		&operator++();
		Fixed		&operator--();
		Fixed		operator++(int);
		Fixed		operator--(int);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const; 

		static Fixed const &		max(Fixed const & a, Fixed const & b);
		static Fixed &				max(Fixed  & a, Fixed & b);
		static Fixed const &		min(Fixed const & a, Fixed const & b);
		static Fixed &				min(Fixed  & a, Fixed & b);

};

std::ostream &		operator<<(std::ostream & o, Fixed const & fp);

#endif
