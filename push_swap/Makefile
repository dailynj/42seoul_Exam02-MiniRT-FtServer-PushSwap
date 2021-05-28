# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 18:01:31 by najlee            #+#    #+#              #
#    Updated: 2021/05/28 18:01:32 by najlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC		=	main.c list_util_1.c list_util_2.c \
			cmd_1.c cmd_2.c libft_1.c error_check.c \
			quick_sort.c  sort_1.c sort_2.c sort_3.c free.c\

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR),$(SRC))
OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CF) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CF) $(SRCS) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean	all

.PHONY	:	all clean fclean re
