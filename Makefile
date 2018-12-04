# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 09:28:09 by ayguillo          #+#    #+#              #
#    Updated: 2018/12/03 19:04:40 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <stdio.h>

NAME = fillit

LIBFT = libft

INCLUDES = ./includes

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

SRCS = main.c \
	   input_to_list.c \
	   tools.c \
	   rec.c \
	   place_tetriminos.c \
	   shift_array.c \
	   output.c \
	   bonus_ncurses.c \

INCS = libft.h fillit.h

SRCDIR = ./srcs/
LIBDIR = ./libft/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))
INCLUDES = $(addprefix $(SRCDIR), $(INCS))
OBJECTS = $(addprefix objs/,$(notdir $(SRCS:.c=.o)))

LIBRARIES = -lft

all : $(NAME)

$(NAME) : $(OBJECTS) $(addprefix $(LIBDIR), libft.a)
	@echo -n 'Compiling $(NAME): '
	@if $(CC) -lncurses -o $(NAME) $(OBJECTS) -L./$(LIBDIR) $(LIBRARIES) ; \
		then echo '✔' ; \
		else echo 'FAILED' ; fi

objs/%.o : srcs/%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $< -I./includes -o $@

$(LIBDIR)libft.a:
	@make -C $(LIBDIR) 

clean :
	@rm -rf $(OBJECTS)
	@make -C $(LIBDIR) clean
	@echo "object deleted ✔"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "$(NAME) deleted ✔"

re : fclean all

.PHONY : all clean fclean re
