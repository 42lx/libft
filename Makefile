NAME = libft.a
SRCS = ft_isalpha.c
# BONUS_SRCS =
OBJ = $(SRCS:.c=.o)
# BONUS_OBJ = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
