/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:42:27 by tdelabro          #+#    #+#             */
/*   Updated: 2018/12/03 16:17:33 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	ft_select(t_list *head, int n_line, int size, \
																	int iter)
{
	if (n_line == 0)
		return ((DREF_HC & 61440) >> (iter % size));
	else if (n_line == 1)
		return (((DREF_HC & 3840) << 4) >> (iter % size));
	else if (n_line == 2)
		return (((DREF_HC & 240) << 8) >> (iter % size));
	else if (n_line == 3)
		return (((DREF_HC & 15) << 12) >> (iter % size));
	else
		return (0);
}

void					ft_addtetri(t_list *head, unsigned short *map, \
														int size, int pos)
{
	int	nb_elem;

	nb_elem = ft_div_arr_sup((size * size), 16);
	ft_l_shift(map, pos, nb_elem);
	map[0] = map[0] | (DREF_HC & 61440);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] | ((DREF_HC & 3840) << 4);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] | ((DREF_HC & 240) << 8);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] | ((DREF_HC & 15) << 12);
	ft_r_shift(map, size * 3 + pos, nb_elem);
	head->content_size = pos;
}

void					ft_deltetri(t_list *head, unsigned short *map, \
														int size, int pos)
{
	int	nb_elem;

	nb_elem = ft_div_arr_sup((size * size), 16);
	ft_l_shift(map, pos, nb_elem);
	map[0] = map[0] ^ (DREF_HC & 61440);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] ^ ((DREF_HC & 3840) << 4);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] ^ ((DREF_HC & 240) << 8);
	ft_l_shift(map, size, nb_elem);
	map[0] = map[0] ^ ((DREF_HC & 15) << 12);
	ft_r_shift(map, size * 3 + pos, nb_elem);
	head->content_size = -1;
}

static void				ft_init_tab(int tab[3], int size, int iter)
{
	tab[0] = ft_div_arr_sup((size * size), 16);
	tab[1] = size * (iter / size);
	tab[2] = 0;
}

int						ft_place_tetri(t_list *head, unsigned short *map, \
															int size, int iter)
{
	int	tab[3];

	ft_init_tab(tab, size, iter);
	ft_l_shift(map, tab[1], tab[0]);
	if (((ft_select(head, 0, size, iter) & (map[0] | \
						(65535 / ft_pwd(2, size)))) == 0) && (tab[1] += size))
	{
		ft_l_shift(map, size, tab[0]);
		if (((ft_select(head, 1, size, iter) & (map[0] | \
						(65535 / ft_pwd(2, size)))) == 0) && (tab[1] += size))
		{
			ft_l_shift(map, size, tab[0]);
			if (((ft_select(head, 2, size, iter) & (map[0] | \
						(65535 / ft_pwd(2, size)))) == 0) && (tab[1] += size))
			{
				ft_l_shift(map, size, tab[0]);
				if ((ft_select(head, 3, size, iter) & (map[0] | \
						(65535 / ft_pwd(2, size)))) == 0)
					tab[2] = 1;
			}
		}
	}
	ft_r_shift(map, tab[1], tab[0]);
	return (tab[2]);
}
