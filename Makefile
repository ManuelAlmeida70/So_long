NAME = so_long
SRCS = $(wildcard *.c)
OBJ_DIR = objs
OBJS = $(SRCS:%c.=$(OBJ_DIR)/%.o)
MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
CFLAGS = -I$(MLX_DIR) -I. -Wall -Wextra -Werror
CC = cc

all: $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJS)
	@echo "Compilando libft"
	@make -C libft
	@echo "Compilando so_long"
	$(CC) $(OBJS) -L./libft -lft $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)

run:
	valgrind --leak-check=full -s ./so_long maps/map.ber

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C libft clean

re: fclean all

.PHONY: all clean fclean re
