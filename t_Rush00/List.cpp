/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:31:16 by afokin            #+#    #+#             */
/*   Updated: 2018/06/24 17:31:18 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"List.hpp"
#include	<iostream>

List::List()
{
	_root = 0;
	_size = 0;
}

List::~List()
{
	node	*ptr;

	ptr = _root;
	while (_root)
	{
		delete _root->cont;
		ptr = _root;
		_root = _root->next;
		delete ptr;
	}
}

List::List(List const & l)
{
	*this = l;
}

List &			List::operator=(List const & l)
{
	this->_root = l._root;
	this->_size = l._size;

	return (*this);
}

void *			List::operator[](int i)
{
	node	*ptr;

	if (i >= this->_size)
		return (0);
	ptr = this->_root;
	for (int j = 0; j < i; j++)
		ptr = ptr->next;
	
	return (ptr->cont);
}

void			List::push(Object *cont)
{
	node	*ptr = new node();

	this->_size++;
	ptr->cont = cont;
	ptr->next = this->_root;
	this->_root = ptr;
}

void			List::erase(int i)
{
	node	*ptr = this->_root;
	node	*del = this->_root;

	for (int j = 0; j < i; j++)
	{
		ptr = del;
		del = del->next;
	}
	if (_size == 0)
		_root = 0;
	del->cont->f = 0;
}

int				List::size() const
{
	return (_size);
}


