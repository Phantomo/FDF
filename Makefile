NAME = fdf

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 

HEAD = -I fdf.h -I libft_gnl/includes  -L libft_gnl -lft -L minilibx/

SRC = resources/fdf.c resources/func.c resources/maping.c resources/key_action.c resources/grad_pix_to_im.c resources/dop_func.c resources/isometric.c

SRCO = $(SRC:%.c=%.o)

all: $(NAME)


$(NAME):
	@ gcc -o $(NAME) $(SRC) $(FLAGS) $(HEAD)
clean:
	@ rm -f $(SRCO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all