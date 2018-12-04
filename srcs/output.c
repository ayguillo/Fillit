/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:58:38 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/03 19:48:37 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_map_v(int size)
{
	char	*c_map;
	int		i;
	int		j;

	if (!(c_map = (char*)malloc(sizeof(char) * ((size * size) + size))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ((size * size) + size))
	{
		if (j == size + 1 || i == size)
		{
			j = 0;
			c_map[i] = '\n';
		}
		else
			c_map[i] = '.';
		j++;
		i++;
	}
	c_map[i] = '\0';
	return (c_map);
}

char		*ft_print_map(t_list *head, int size)
{
	char		*final_map;
	int			tab[4];

	tab[3] = 'A' - 1;
	final_map = (ft_map_v(size));
	while (head != NULL && (tab[3]++))
	{
		tab[0] = head->content_size + (head->content_size / size);
		tab[1] = -1;
		tab[2] = -1;
		while (++tab[1] < 4)
		{
			tab[2] = -1;
			while (++tab[2] < 4)
			{
				if ((DREF_HC & 32768) == 32768)
					final_map[tab[0]] = tab[3];
				DREF_HC = DREF_HC << 1;
				tab[0]++;
			}
			tab[0] = tab[0] - 3 + size;
		}
		head = head->next;
	}
	return (final_map);
}
