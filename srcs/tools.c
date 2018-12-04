/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:07:33 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/03 18:50:36 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_arr_sup(int n)
{
	int res;

	res = 1;
	if (n <= 0 && n >= 214483600)
		return (0);
	while ((res * res) <= n)
	{
		res++;
		if (res * res == n)
			return (res);
	}
	return (ft_sqrt_arr_sup(n + 1));
}

int		ft_div_arr_sup(int nb, int div)
{
	int res;

	if (nb <= 0 || div <= 0)
		return (0);
	if (div == 1)
		return (nb);
	res = (nb / div) + 1;
	return (res);
}

void	ft_initmapcpy(unsigned short *map,
		unsigned short *cpy, int nb_elem, int size)
{
	int i;
	int tmp;

	i = 0;
	while (i < nb_elem)
	{
		cpy[i] = map[i];
		i++;
	}
	tmp = ft_pwd(2, (16 - (nb_elem * 16 - (size * size))));
	if (tmp != 0)
		cpy[nb_elem - 1] = cpy[nb_elem - 1] | (65535 / tmp);
}

void	ft_left_and_up(t_list *head)
{
	while ((DREF_HC & 61440) == 0)
		DREF_HC = DREF_HC << 4;
	while ((DREF_HC & 34952) == 0)
		DREF_HC = DREF_HC << 1;
}
