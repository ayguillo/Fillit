/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:32:55 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/03 18:47:53 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <ncurses.h>

# define DREF_HC (*((unsigned short*)(head->content)))
# define HCS head->content_size

void			ft_print_tmp(unsigned short *map, int size);
t_list			**ft_fill_list(int fd);
int				ft_sqrt_arr_sup(int n);
int				ft_div_arr_sup(int nb, int div);
int				ft_create_map(t_list **lst, int size, int nb_elem);
void			ft_initmapcpy(unsigned short *map, unsigned short *cpy, \
											int nb_elem, int size);
int				ft_place_tetri(t_list *head, unsigned short *map, \
											int size, int iter);
void			ft_l_shift(unsigned short *map, int shift, int size);
void			ft_r_shift(unsigned short *map, int shift, int size);
char			*ft_print_map(t_list *head, int size);
void			ft_printcolor(char *str);
void			ft_addtetri(t_list *head, unsigned short *map,
		int size, int pos);
void			ft_deltetri(t_list *head, unsigned short *map,
		int size, int pos);
void			ft_left_and_up(t_list *head);
void			ft_addtetri(t_list *head, unsigned short *map, \
												int size, int pos);
void			ft_deltetri(t_list *head, unsigned short *map, \
												int size, int pos);

#endif
