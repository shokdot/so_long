NAME = libft.a
SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)
RM = rm -f
C_FLAGS = -Wall -Wextra -Werror -c

all:$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS) $(BOUNUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re:fclean all

%.o:%.c
	@cc $(C_FLAGS) $< -o $@

.PHONY: all bonus clean fclean re
