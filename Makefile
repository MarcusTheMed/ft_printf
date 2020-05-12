LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
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

SURPL_O = 	ft_view_width.o \
			ft_view.o \
			ft_view_width.o \
			ft_uns_itoa.o \
			ft_nbr_base.o \
			ft_putchar.o \
			ft_str_tolower.o \
			ft_putstr.o \
			ft_view_str.o \
			ft_view_char.o \
			ft_view_ptr.o \
			ft_view_int.o \
			ft_view_uint.o \
			ft_view_percent.o \
			ft_view_hex.o \
			ft_view_flags.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf $(SURPL_O)
	@rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
