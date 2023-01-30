# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:24:11 by bfresque          #+#    #+#              #
#    Updated: 2023/01/30 15:55:28 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -g3 #-Werror

GREEN = \033[92m
YELLOW = \033[33m
NEUTRAL = \033[0m
I = \033[3m

SRCS =	srcs/check_bordures.c \
		srcs/check_items.c \
		srcs/check_map.c \
		srcs/check_path.c \
		srcs/so_long.c \
		srcs/utils.c \
		srcs/put_in_tab.c \
		srcs/put_in_windows.c \
		srcs/move_player.c \
		libft/libft/ft_split.c \
		libft/libft/ft_strdup.c \
		libft/libft/ft_substr.c \
		libft/get_next_line/get_next_line.c \
		libft/get_next_line/get_next_line_utils.c \
		libft/ft_printf/ft_print_b16.c \
		libft/ft_printf/ft_print_nbr.c \
		libft/ft_printf/ft_print_ptr.c \
		libft/ft_printf/ft_print_str.c \
		libft/ft_printf/ft_print_unbr.c \
		libft/ft_printf/ft_printf.c \

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx-Imlx -O3 -c $< -o $@
	@echo "$(I)$(YELLOW)Compilating ... $(NEUTRAL)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lminilibx -lmlx -Lminilibx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)Compilation Done $(NEUTRAL)"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "$(GREEN)Object files removed $(NEUTRAL)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Binary file removed $(NEUTRAL)"

re : fclean all

.PHONY: all clean fclean re
