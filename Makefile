# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 19:06:42 by csnowbal          #+#    #+#              #
#    Updated: 2020/05/12 21:25:45 by csnowbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEAD = ./includes/ft_printf.h
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS =  sources/ft_printf.c \
		sources/ft_view.c \
		sources/ft_view_width.c \
		sources/ft_uns_itoa.c \
		sources/ft_nbr_base.c \
		sources/ft_putchar.c \
		sources/ft_str_tolower.c \
		sources/ft_putstr.c \
		sources/ft_view_str.c \
		sources/ft_view_char.c \
		sources/ft_view_ptr.c \
		sources/ft_view_int.c \
		sources/ft_view_uint.c \
		sources/ft_view_percent.c \
		sources/ft_view_hex.c \
		sources/ft_view_flags.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -f

%.o : %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(ARRC) $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(REMF) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(REMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
