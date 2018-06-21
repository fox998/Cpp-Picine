/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:46:11 by afokin            #+#    #+#             */
/*   Updated: 2018/06/20 15:46:14 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(void): _fpval(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int			Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fpval);
}

Fixed 		&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fpval = copy.getRawBits();
	return (*this);
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpval = raw;
}
