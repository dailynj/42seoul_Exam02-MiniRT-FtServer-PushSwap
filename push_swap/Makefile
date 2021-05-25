NAME	=	push_swap

CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC		=	src/push_swap.c src/list_util_1.c src/list_util_2.c \
			src/cmd_1.c src/cmd_2.c \

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)
			ranlib $(NAME)

%.o		:	%.c
			$(CC) $(CF) -c $<

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean	all

.PHONY	:	all clean fclean re