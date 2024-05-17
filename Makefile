NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
SUBDIRS = parsing
MLX_LIB = ./mlx
INCLUDES = ./includes

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit
CFLAGS = -I # -Wall -Wextra -Werorr

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(OBJ_DIR): mlxlib
	@mkdir -p $(OBJ_DIR)

mlxlib:
	@make -C $(MLX_LIB)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(MLX_FLAGS) $(OBJ) -o $(NAME)
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
	@echo "$(RED)Deleting all files"

re: fclean all

.PHONY: all clean re fclean mlxlib
