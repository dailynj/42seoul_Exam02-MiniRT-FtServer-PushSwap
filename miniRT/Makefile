# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by najlee            #+#    #+#              #
#    Updated: 2021/04/09 20:04:01 by najlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	\
			minirt.c \
			vec_operation.c \
			ray.c \
			color.c \
			sphere.c \

#
#
#

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
