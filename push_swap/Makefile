NAME	=	push_swap

CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC		=	push_swap.c list.c \

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make all -C ./libft
			cp ./libft/libft.a $(NAME)
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