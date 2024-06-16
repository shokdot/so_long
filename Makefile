NAME = so_long

SRC_DIR = src
OBJ_DIR = build
SUBDIRS = parsing utils game

MLX_LIB = ./mlx
LIBFT = ./libft

INCLUDES = -I includes
HEADER = $(wildcard includes/*.c)

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFLAGS = -L mlx -L libft -l mlx -l ft
MLXFLAGS = -framework OpenGL -framework AppKit
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3

GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

all: $(NAME)

$(OBJ_DIR): libs
	@mkdir -p $(OBJ_DIR)

libs:
	@make -C $(LIBFT)
# @make -C $(MLX_LIB)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) So_Long is waiting for you!$(RESET)"

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
	@echo "$(RED) Deleting so_long!$(RESET)"

re: fclean all

.PHONY: all clean re fclean libs
