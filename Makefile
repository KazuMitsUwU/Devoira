# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 16:39:53 by manoaran          #+#    #+#              #
#    Updated: 2026/05/15 07:12:18 by sitrakaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   push_swap
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

PRINTF_DIR  =   ft_printf
PRINTF_LIB  =   $(PRINTF_DIR)/libftprintf.a

INCLUDES	=	-I. -I$(PRINTF_DIR)

SRC 		=	main.c \
				ft_split.c \
				helpers.c \
				bench.c \
				parsing.c \
				parsing_utils.c \
				parsing_make_clean_list.c \
				parsing_check_args.c \
				stack_utils.c \
				position_utils.c \
				disorder_metric.c \
				sa_sb_ss.c \
				pa_pb.c \
				ra_rb_rr.c \
				rra_rrb_rrr.c \
				simple_sort.c \
				medium_sort.c \
				complex_sort.c \
				adaptive_sort.c\
				str_utils.c\
				cleanup.c\
				stack_free.c

OBJ         =   $(SRC:.c=.o)

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
