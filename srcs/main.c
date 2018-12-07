/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:27:12 by tdelabro          #+#    #+#             */
/*   Updated: 2018/12/03 19:58:30 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(int ac, char **av)
{
	int fd;
	int ret;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [-v] ] file\n");
		return (-1);
	}
	if (((fd = open(av[1], O_RDONLY)) == -1) ||
			((ret = read(fd, NULL, 0)) == -1))
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (fd);
}

int			main(int ac, char **av)
{
	t_list	**lst;
	int		fd;
	int		size_min;
	int		valid_size;
	char	*map;

	if ((fd = ft_error(ac, av)) == -1)
		return (1);
	if (!(lst = ft_fill_list(fd)))
	{
		ft_putstr("error\n");
		return (1);
	}
	size_min = ft_sqrt_arr_sup(ft_lstlen(*lst) * 4);
	valid_size = ft_create_map(lst, size_min,
			ft_div_arr_sup((size_min * size_min), 16));
	map = ft_print_map(*lst, valid_size);
	if (ft_strcmp(av[1], "-v") != 0)
		ft_putstr(map);
	else
		ft_printcolor(map);
	free(map);
	ft_lstclear(lst);
	return (0);
}
