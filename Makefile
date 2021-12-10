MAKEFLAGS += -s

NAME		=	fractol

SRC			= 	fractol.c \
				mandelbrot.c julia.c \
				utils.c init.c colors.c hooks.c help.c key_press.c

OBJ			=	$(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Werror -Wextra -I./libft
MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
#HEADERS	=	fractol.h mlx/mlx.h


all:
			@make -C ./libft/
			@make -C ./mlx/
			@make $(NAME)

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) mlx/libmlx.a $(OBJ) $(MLXFLAGS) ./libft/libft.a -o $(NAME) -fsanitize=address -ggdb3
			@printf "\x1b[32mFractol is ready!\n"
			@printf "\x1b[34mEnter fractal's name: mandelbrot or julia.\n"

#-fsanitize=address

%.o : 		%.c 
			@gcc $(CFLAGS) -Ofast -c $< -o $@

clean:
			@rm -rf $(OBJ)
			@make clean -C ./libft/
			@make clean -C ./mlx/

fclean: 	clean
			@rm -rf $(NAME)
			@make fclean -C ./libft/

re: 		fclean all
			
.PHONY: 	all clean fclean re