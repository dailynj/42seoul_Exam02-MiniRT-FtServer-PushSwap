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

NAME1	=	push_swap
NAME2	=	checker

CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC1	=	push_swap.c init_info_1.c init_info_2.c pop_push.c \
			instruction_1.c instruction_2.c libft.c error_check.c \
			quick_sort.c  sort_1.c sort_2.c sort_3.c sort_4.c free.c \
			free_2.c cmd.c classification.c optimization.c \
			push_tail_srp_1.c push_tail_srp_2.c \

SRC2	=	checker.c init_info_1.c init_info_2.c pop_push.c\
			instruction_1.c instruction_2.c libft.c error_check.c \
			quick_sort.c  sort_1.c sort_2.c sort_3.c sort_4.c free.c \
			free_2.c cmd.c  classification.c optimization.c \
			push_tail_srp_1.c push_tail_srp_2.c \

SRC_DIR = ./src/

SRCS1 = $(addprefix $(SRC_DIR),$(SRC1))
SRCS2 = $(addprefix $(SRC_DIR),$(SRC2))

OBJ1 = $(SRCS1:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

all		:	$(NAME1) $(NAME2)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CF) -c $< -o $@

$(NAME1): $(OBJ)
	$(CC) $(CF) $(SRCS1) -o $(NAME1)

$(NAME2): $(OBJ)
	$(CC) $(CF) $(SRCS2) -o $(NAME2)

clean	:
			rm -f $(OBJ1) $(OBJ2)

fclean	:	clean
			rm -f $(NAME1)
			rm -f $(NAME2)

re		:	fclean	all

.PHONY	:	all clean fclean re
