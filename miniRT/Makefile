# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by najlee            #+#    #+#              #
#    Updated: 2021/05/17 01:16:27 by najlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

SRCS	=	\
			src/mlx.c \
			src/key_hook.c \
			src/main.c \
			src/bmp.c \
			src/color.c \
			src/ray.c \
			src/point.c \
			src/object.c \
			src/light.c \
			src/scene.c \
			src/shadow.c \
			src/hit.c \
			\
			src/object/sphere.c \
			src/object/plane.c \
			src/object/square.c \
			src/object/triangle.c \
			src/object/cylinder.c \
			\
			src/gnl/get_next_line_utils.c \
			src/gnl/get_next_line.c \
			\
			src/parsing/parse.c \
			src/parsing/parse_2.c \
			src/parsing/parse_racl.c \
			src/parsing/parse_object.c \
			src/parsing/parse_object2.c \
			src/parsing/parse_util.c \
			\
			src/libft/split_char.c \
			src/libft/split_whitespace.c \
			src/libft/libft_1.c \
			src/libft/libft_2.c \
			src/libft/libft_3.c \
			\
			src/vector/vec_1.c \
			src/vector/vec_2.c \
			src/vector/vec_3.c \



OBJS = $(SRCS:%.c=%.o)

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx


all		: $(NAME)

bonus	: all

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

.PHONY: all clean fclean re
