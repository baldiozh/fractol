NAME		=	fractol

SRC			= 	fractol.c ft_putstr.c ft_strcmp.c mandelbrot.c utils.c init.c

OBJ			=	${SRC:.c=.o}

FLAGS		=	-Wall -Werror -Wextra

HEADER		=	fractol.h mlx/mlx.h

MLX			=	libmlx.a

all:		$(NAME) mlx/

$(NAME):	$(MLX) $(OBJ) $(HEADER)
			gcc $(FLAGS) mlx/libmlx.a  $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
			make -C mlx

clean:
			rm -rf ${OBJ} ${OBJ_bonus} mlx/*.o

fclean: 	clean
			rm -rf ${NAME} ${NAME_bonus} mlx/libmlx.a

re: 		fclean all
			
.PHONY: 	all clean fclean re