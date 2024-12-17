# Project Name
NAME = so_long

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Colors
GREEN = \033[92m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
RESET = \033[0m

# Directories
SRCS_DIR = srcs/
LIBFT_DIR = libft/libft/
GNL_DIR = libft/get_next_line/
PRINTF_DIR = libft/ft_printf/
OBJS_DIR = obj/
MLX_DIR = includes/minilibx-linux/
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

# MinilibX Flags
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lX11 -lXext -lm
MLX_INCLUDE = -I $(MLX_DIR)
MLX_LIB = $(MLX_DIR)libmlx.a
MLX_CLONED := $(shell [ -d $(MLX_DIR) ] && echo 1)

# Source and Object Files
SRCS = $(SRCS_DIR)check_bordures.c \
       $(SRCS_DIR)check_items.c \
       $(SRCS_DIR)check_map.c \
       $(SRCS_DIR)check_path.c \
       $(SRCS_DIR)so_long.c \
       $(SRCS_DIR)utils.c \
       $(SRCS_DIR)put_in_tab.c \
       $(SRCS_DIR)put_in_windows.c \
       $(SRCS_DIR)move_player.c \
       $(SRCS_DIR)close_game.c

LIBFT_SRCS = $(LIBFT_DIR)ft_split.c \
             $(LIBFT_DIR)ft_strdup.c \
             $(LIBFT_DIR)ft_substr.c

GNL_SRCS = $(GNL_DIR)get_next_line.c \
           $(GNL_DIR)get_next_line_utils.c

PRINTF_SRCS = $(PRINTF_DIR)ft_print_b16.c \
              $(PRINTF_DIR)ft_print_nbr.c \
              $(PRINTF_DIR)ft_print_ptr.c \
              $(PRINTF_DIR)ft_print_str.c \
              $(PRINTF_DIR)ft_print_unbr.c \
              $(PRINTF_DIR)ft_printf.c

# Object Files
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
LIBFT_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(LIBFT_SRCS:.c=.o)))
GNL_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(GNL_SRCS:.c=.o)))
PRINTF_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(PRINTF_SRCS:.c=.o)))

ALL_OBJS = $(OBJS) $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Rules
all: mlx $(NAME)

# Clone and Build MinilibX with a progress bar
mlx:
ifeq ($(MLX_CLONED),)
	@echo "$(CYAN)\nCloning MinilibX repository...$(RESET)"
	@git clone $(MLX_REPO) $(MLX_DIR) > /dev/null 2>&1
	@echo "$(YELLOW)Compiling MinilibX... Please wait...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1 & \
	{ \
		for i in $$(seq 1 100); do \
			sleep 0.02; \
			printf "$(GREEN)\r[%-50s] %d%%$(RESET)" "$$(printf '#%.0s' $$(seq 1 $$(($$i / 2))))" "$$i"; \
		done; \
	}
	@echo "\n$(GREEN)MinilibX compiled successfully!$(RESET)"
else
	@echo "$(GREEN)MinilibX already exists. Skipping clone.$(RESET)"
endif

# Compile the project
$(NAME): $(ALL_OBJS)
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation Done!$(RESET)"

# Create obj/ directory and compile object files
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@
	@echo "$(YELLOW)Compiling $< into $(notdir $@)...$(RESET)"

$(OBJS_DIR)%.o: $(LIBFT_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $< into $(notdir $@)...$(RESET)"

$(OBJS_DIR)%.o: $(GNL_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $< into $(notdir $@)...$(RESET)"

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $< into $(notdir $@)...$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)Creating obj directory...$(RESET)"

# Clean up
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Binary removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re mlx
