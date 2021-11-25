NAME		=	fractol

SRC			= 	fractol.c \
				mandelbrot.c \
				utils.c init.c colors.c hooks.c help.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	gcc -Wall -Werror -Wextra
MLXFLAGS	=	-framework OpenGL -framework AppKit

HEADERS		=	fractol.h -I mlx -I libft

MLX			=	libmlx.a

LIBFT		=	libft.a

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(OBJ) $(HEADERS)
			$(CFLAGS) mlx/libmlx.a libft/libft.a $(OBJ) $(MLXFLAGS) -o $(NAME)

$(MLX):
			make -C mlx

$(LIBFT):	make -C libft

clean:
			rm -rf $(OBJ) mlx/*.o libft/*.o

fclean: 	clean
			rm -rf $(NAME) mlx/libmlx.a libft/libft.a

re: 		fclean all
			
.PHONY: 	all clean fclean re