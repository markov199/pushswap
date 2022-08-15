# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 12:09:04 by mkovoor           #+#    #+#              #
#    Updated: 2022/08/15 12:22:33 by mkovoor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SCRS = pushswap.c pushswap_moves.c pushswap_utils.c \
		pushswap_sort.c pushswap_errors.c ft_lstprint.c \
		pushswap_chunk.c
OBJS = $(SCRS:.c=.o)

all:libft/libft.a $(NAME)

libft/libft.a:
	$(MAKE) all -C libft

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) libft/libft.a $(OBJS) -o push_swap
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re:fclean all

.PHONY: all clean fclean re
	
