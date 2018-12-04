/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:54:34 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/03 16:20:35 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_l_shift(unsigned short *map, int shift, int size)
{
	int				i;
	unsigned short	last;
	unsigned short	first;

	while (shift >= 1)
	{
		last = 0;
		first = 0;
		i = size - 1;
		while (i >= 0)
		{
			first = map[i] & 32768;
			map[i] = (map[i] << 1) | last;
			last = first >> 15;
			i--;
		}
		map[size - 1] = map[size - 1] | last;
		shift--;
	}
}

void		ft_r_shift(unsigned short *map, int shift, int size)
{
	int				i;
	unsigned short	last;
	unsigned short	first;

	while (shift >= 1)
	{
		last = 0;
		first = 0;
		i = 0;
		while (i < size)
		{
			last = map[i] & 1;
			map[i] = (map[i] >> 1) | first;
			first = last << 15;
			i++;
		}
		map[0] = map[0] | first;
		shift--;
	}
}
