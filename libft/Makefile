NAME		=	libft.a
SRC			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_memchr.c \
				ft_strdup.c ft_strchr.c ft_calloc.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_strncmp.c ft_memmove.c ft_atoi.c \
				ft_strrchr.c ft_strlcpy.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlcat.c ft_strlen.c ft_bzero.c \
				ft_putendl_fd.c ft_itoa.c ft_substr.c ft_strnstr.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c
OBJ			= $(SRC:.c=.o)
CFLAGS		= -Wall -Werror -Wextra
HEADER		= libft.h

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			gcc $(CFLAGS) $(HEADER) $(OBJ) -o $<
			ar -r $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
