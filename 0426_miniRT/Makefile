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
			src/minirt.c \
			src/color.c \
			src/ray.c \
			src/vec.c \
			src/object/sphere.c \
			src/point.c \
			src/object.c \
			src/light.c \
			src/scene.c \
			src/shadow.c \
			src/object/plane.c \
			src/hit.c \
			src/object/square.c \
			src/object/triangle.c \
			src/object/cylinder.c \
			src/gnl/get_next_line_utils.c \
			src/gnl/get_next_line.c \

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

test	: re
		./a.out
