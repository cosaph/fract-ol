NAME = libft.a

DEPS = libft.h

SRC=$(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(DEPS)
	@echo "$(ROSE)Creating library $(NAME)...$(NC)"
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(notdir $(SRC:.c=.o))

%.o: %.c $(DEPS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning library $(NAME)...$(NC)"
	rm -f $(NAME)

re: fclean all

t: $(NAME)
	@$(CC) $(CFLAGS) main.c -L. -lft -o test
	@./test

.PHONY: all clean fclean re t