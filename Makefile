NAME		=	fractol

SRC			= 	fractol.c \
				mandelbrot.c julia.c \
				utils.c init.c colors.c hooks.c help.c

OBJ			=	$(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Werror -Wextra -I./libft
MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
#HEADERS		=	fractol.h mlx/mlx.h


all:
			@make -C ./libft/
			@make -C ./mlx/
			@make $(NAME)

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) mlx/libmlx.a $(OBJ) $(MLXFLAGS) ./libft/libft.a -o $(NAME)
			@printf "\x1b[32mFractol is ready to use!\n"

%.o : 		%.c 
			@gcc $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJ)
			@make clean -C ./libft/
			@make clean -C ./mlx/

fclean: 	clean
			@rm -rf $(NAME)
			@make fclean -C ./libft/

re: 		fclean all
			
.PHONY: 	all clean fclean re