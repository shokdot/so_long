NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
SUBDIRS = parsing utils gnl
MLX_LIB = ./mlx
LIBFT = ./libft
INCLUDES = ./includes

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFLAGS = -L mlx -L libft -l mlx -l ft
MLXFLAGS = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -g3 -I

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(OBJ_DIR): libs
	@mkdir -p $(OBJ_DIR)

libs:
	@make -C $(LIBFT)
	@make -C $(MLX_LIB)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(MLX_LIB)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)Deleting all files"

re: fclean all

.PHONY: all clean re fclean mlxlib
