# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 12:48:29 by csnowbal          #+#    #+#              #
#    Updated: 2020/05/12 21:22:10 by csnowbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)
CC = gcc
FlAG = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -f

%.o : %.c $(HEAD)
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJB)
	$(ARRC) $(NAME) $(OBJS) $(OBJB)

clean:
	@$(REMF) $(OBJS) $(OBJB)

fclean: clean
	@$(REMF) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
