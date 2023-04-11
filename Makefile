SRC =	./libft/ft_putchar_fd.c \
		./libft/ft_strdup.c \
		./libft/ft_strlen.c \
		ft_printf.c \
		print_c.c \
		print_nbr.c \
		print_s.c \
		print_hex_ptr.c

NAME = libftprintf.a

OBJS = ./*.o

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

RM = rm -rf

HEADER = ./

all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
