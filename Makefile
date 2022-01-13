SRC =	./libft/*.c \
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

TEST = ./main.c


all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test: re
	$(GCC) -I$(HEADER) $(TEST) $(NAME)
	./a.out

lib: all clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
