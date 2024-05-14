NAME = so_long
SRC_DIR = src
SUBDIRS =
SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRC	= $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
INCLUDES = $(wildcard includes/*.h)
OBJ_DIR = obj
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
CFLAGS = -I # -Wall -Wextra -Werror -I
RM = rm -f

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) Makefile $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c Makefile $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./mlx

fclean: clean
	@$(RM) $(NAME)

re: fclean all


