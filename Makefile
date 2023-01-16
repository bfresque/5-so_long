# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:24:11 by bfresque          #+#    #+#              #
#    Updated: 2023/01/16 11:08:40 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra #-Werror

SRCS = main.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx -lmlx -Lminilibx -lXext -lX11 -lm -lz -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

