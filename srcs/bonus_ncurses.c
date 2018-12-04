/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:31:01 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/04 10:37:27 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_init_color(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_GREEN, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(12, COLOR_BLUE, COLOR_CYAN);
	init_pair(13, COLOR_BLUE, COLOR_WHITE);
	init_pair(14, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(15, COLOR_GREEN, COLOR_YELLOW);
	init_pair(16, COLOR_GREEN, COLOR_BLUE);
	init_pair(17, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(18, COLOR_CYAN, COLOR_BLACK);
	init_pair(19, COLOR_GREEN, COLOR_WHITE);
}

static void	ft_init_color2(void)
{
	init_pair(20, COLOR_WHITE, COLOR_RED);
	init_pair(21, COLOR_WHITE, COLOR_GREEN);
	init_pair(22, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(23, COLOR_WHITE, COLOR_BLACK);
	init_pair(24, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(25, COLOR_CYAN, COLOR_RED);
	init_pair(26, COLOR_RED, COLOR_CYAN);
	init_pair(27, COLOR_BLACK, COLOR_BLACK);
}

static void	ft_loop(char c)
{
	int		j;
	char	s;

	if (c >= 'A' && c <= 'Z')
	{
		j = 1;
		s = '@';
		while (++s != c)
			j++;
		attron(COLOR_PAIR(j));
	}
}

void		ft_printcolor(char *str)
{
	int		i;

	initscr();
	ft_init_color();
	ft_init_color2();
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			attron(COLOR_PAIR(27));
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_loop(str[i]);
		attron(A_NORMAL);
		printw("%c", str[i]);
		refresh();
	}
	getch();
	endwin();
}
