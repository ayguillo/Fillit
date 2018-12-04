/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:54:38 by tdelabro          #+#    #+#             */
/*   Updated: 2018/12/03 15:30:39 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_rec(t_list *head, unsigned short *map, int size, int nb_elem)
{
	unsigned short	map_bis[nb_elem];
	int				iter;

	if (head == NULL)
		return (1);
	ft_initmapcpy(map, map_bis, nb_elem, size);
	iter = -1;
	while (++iter < size * size)
	{
		if (ft_place_tetri(head, map_bis, size, iter) == 1)
		{
			ft_addtetri(head, map_bis, size, iter);
			if (ft_rec(head->next, map_bis, size, nb_elem) == 1)
				return (1);
			ft_deltetri(head, map_bis, size, iter);
		}
	}
	return (-1);
}

int			ft_create_map(t_list **lst, int size, int nb_elem)
{
	unsigned short	map[nb_elem];
	t_list			*head;
	int				i;

	i = -1;
	while (++i < nb_elem)
		map[i] = 0;
	map[nb_elem - 1] = map[nb_elem - 1] & (65535 / ft_pwd(2, 16 - \
									((nb_elem * 16) - (size * size))));
	head = *lst;
	while (head)
	{
		head->content_size = -1;
		head = head->next;
	}
	head = *lst;
	i = ft_rec(head, map, size, nb_elem);
	if (i == -1)
		return (ft_create_map(lst, size + 1, \
					ft_div_arr_sup(((size + 1) * (size + 1)), 16)));
	else
		return (size);
}
