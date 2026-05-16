NAME    =   libftprintf.a
CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRC     =   ft_printf.c ft_putnbr.c print_utils.c str_utils.c
OBJ     =   $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
