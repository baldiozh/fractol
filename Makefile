NAME		=	fractol

SRC			= 	fractol.c \
				ft_putchar_fd ft_atoi.c
				mandelbrot.c \
				utils.c init.c colors.c hooks.c help.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS	=	-framework OpenGL -framework AppKit

HEADERS		=	fractol.h -I mlx -I libft

all:		$(NAME) mlx 

$(NAME):	$(MLX) $(OBJ) $(HEADERS)
			gcc $(CFLAGS) mlx/libmlx.a $(OBJ) $(MLXFLAGS) -o $(NAME)
 

MLX:		
			make -C mlx

clean:
			rm -rf $(OBJ) mlx/*.o 

fclean: 	clean
			rm -rf $(NAME) mlx/libmlx.a

re: 		fclean all
			
.PHONY: 	all clean fclean re