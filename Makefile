# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 16:39:53 by manoaran          #+#    #+#              #
#    Updated: 2026/05/14 06:12:00 by sitrakaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -I.

SRC         = main.c \
              helpers.c \
              ft_split.c \
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
              adaptive_sort.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
