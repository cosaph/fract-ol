NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L./ -lmlx -framework OpenGL -framework Appkit
FT_PRINTF = ./ft_printf/libftprintf.a

SRC = ft_arroom.c \
	ft_ideka.c \
	ft_init.c \
	ft_julia.c \
	ft_mandelbrot.c \
	ft_params.c \
	ft_math_utils.c \
	init.c \
	string_utils.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./ft_printf
	echo "\033[1m FT_PRINTF done \033[0m"
	$(MAKE) --no-print-directory -C ./mlx
	echo "\033[1m MiniLibX done \033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(FT_PRINTF) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
