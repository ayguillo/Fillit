/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:31:29 by tdelabro          #+#    #+#             */
/*   Updated: 2018/12/03 18:46:17 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** char *buf is an [22] character buffer : 16 for the shape, 3 for newline
** + 1 final '\0' at input[19].
** There is one more unaccessible character after the '\0',
**	exept for the last read buffer for whitch this byte is undefinied.
**	example :	..##\n
**				...#\n
**				...#\n
**				....\n\n\0
**
** This function maloc a node and change it's ->content (an unsigned short)
** bits in order to make the represent the tetromino's shape.
*/

static t_list	*ft_fill_node(char *buf)
{
	t_list			*head;
	int				i;
	unsigned short	us;

	i = 0;
	us = 0;
	if (!(head = ft_lstnew(&us, sizeof(unsigned short))))
		return (NULL);
	while (i != 19)
	{
		if (buf[i] == '\n')
			i++;
		DREF_HC = DREF_HC << 1;
		if (buf[i++] == '#')
			DREF_HC += 1;
	}
	ft_left_and_up(head);
	return (head);
}

static int		ft_count_link(char *buf, int i)
{
	int c;

	c = 0;
	if (buf[i + 1] == '#')
		c++;
	if (i < 15 && buf[i + 5] == '#')
		c++;
	if (i > 0 && buf[i - 1] == '#')
		c++;
	if (i > 4 && buf[i - 5] == '#')
		c++;
	return (c);
}

/*
** Check if the blobal content of the buffer is a valid tetrimino input
*/

static int		ft_parsing_buf_content(char *buf)
{
	int	i;
	int	c;
	int	l;

	i = -1;
	c = 0;
	l = 0;
	while (buf[++i])
	{
		if (i != 20 && (i % 5 == 0 || i % 5 == 1 || i % 5 == 2 ||
					i % 5 == 3) && buf[i] != '.' && buf[i] != '#')
			return (-1);
		if (i % 5 == 4 && buf[i] != '\n')
			return (-1);
		if (i == 20 && buf[i] != '\n')
			return (-1);
		if (buf[i] == '#' && (c = c + 1))
			l = l + ft_count_link(buf, i);
	}
	if (i != 21 && i != 20)
		return (-1);
	if (l < 5)
		return (-1);
	return (c != 4) ? -1 : 1;
}

/*
** BUFF_SIZE have to be equal to 21
**
** This function create a linked list, each node contains one tetrimino's datas
** It retrurn a pointer to the adress of the first node of the list.
*/

static int		ft_loop(int fd, char *buf, t_list **lst)
{
	t_list	*head;
	int		ret;

	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ft_parsing_buf_content(buf) != 1)
			return (1);
		if (*lst == NULL)
		{
			if (!(head = ft_fill_node(buf)))
				return (1);
			*lst = head;
		}
		else
		{
			if (!(head->next = ft_fill_node(buf)))
				return (1);
			head = head->next;
		}
	}
	return (ret);
}

t_list			**ft_fill_list(int fd)
{
	static t_list	*lst;
	int				ret;
	char			buf[22];

	lst = NULL;
	if ((ret = ft_loop(fd, buf, &lst)) == 1)
		return (NULL);
	if ((ret == 0 && lst == NULL) || buf[20] == '\n')
	{
		ft_lstclear(&lst);
		return (NULL);
	}
	return (&lst);
}
