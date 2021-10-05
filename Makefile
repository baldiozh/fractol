NAME		= fractol

SRC			= 

OBJ			=	${SRC:.c=.o}

FLAGS		=	-Wall -Werror -Wextra

HEADER		=	fractol.h


all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf ${OBJ} ${OBJ_bonus} 

fclean: 	clean
			rm -rf ${NAME} ${NAME_bonus}

re: 		fclean all
			
.PHONY: 	all clean fclean re