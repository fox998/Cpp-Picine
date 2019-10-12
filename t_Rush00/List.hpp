/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:31:39 by afokin            #+#    #+#             */
/*   Updated: 2018/06/24 17:31:42 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIST_HPP
# define	LIST_HPP

#include	"Object.hpp"

class	List
{
	struct	node
	{
		Object	*cont;
		node	*next;

	};

	private:
		node	*_root;
		int		_size;

	public:
		~List();
		List();
		List(List const & copy);

		List &		operator=(List const & l);
		void *		operator[](int i);

		void		push(Object	*content);
		void		erase(int index);
		int			size() const;
};

#endif
