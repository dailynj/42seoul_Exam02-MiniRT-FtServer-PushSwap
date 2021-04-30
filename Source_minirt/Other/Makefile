# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 18:59:15 by hyeonkim          #+#    #+#              #
#    Updated: 2021/01/13 19:24:28 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minirt
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MAKE	= make
INCLUDE	= -I./include -I./mlx
LIBDIR	= ./libft
LIBFT	= libft.a
MLXDIR	= ./mlx
MLX		= libmlx.dylib
LIBFLAG	= -L $(MLXDIR) -lmlx -framework OpenGl -framework Appkit -L $(LIBDIR) -lft
SRC_CONTROL_NAME	= control.c \
					control2.c \
					control_object.c \
					control_object_translate.c \
					control_object_translate2.c \
					control_object_translate3.c \
					control_object_translate4.c \
					control_object_texture.c \
					control_object_scale.c \
					control_object_scale2.c \
					control_object_rotate.c \
					control_light.c \
					control_light2.c \
					control_init.c \
					control_filter.c \
					control_camera.c \
					control_camera2.c \
					console_msg.c \
					save.c
SRC_PARSE_NAME		= read.c \
					parse.c \
					parse2.c \
					parse3.c \
					parse_utils.c \
					error.c \
					error2.c
SRC_SCENE_NAME		= make_object.c \
					make_object2.c \
					make_object3.c \
					make_light.c \
					object_utils.c \
					color.c \
					scene.c
SRC_TRACE_NAME		= filter.c \
					hit_cone.c \
					hit_cube.c \
					hit_cylinder.c \
					hit_disc.c \
					hit_plane.c \
					hit_pyramid.c \
					hit_sphere.c \
					hit_square.c \
					hit_triangle.c \
					hit_utils.c \
					hit_utils2.c \
					hit.c \
					phong_parallel.c \
					phong_spot.c \
					phong_utils.c \
					ray_color.c \
					render_antialiasing.c \
					render_preview.c \
					skybox.c \
					texture.c
SRC_UTILS_NAME		= common_utils.c \
					matrix_utils.c \
					matrix_utils2.c \
					matrix_utils3.c \
					vector_utils.c \
					vector_utils2.c \
					vector_utils3.c
SRC_CONTROL = $(addprefix src/control/, $(SRC_CONTROL_NAME))
SRC_PARSE = $(addprefix src/parse/, $(SRC_PARSE_NAME))
SRC_SCENE = $(addprefix src/scene/, $(SRC_SCENE_NAME))
SRC_TRACE = $(addprefix src/trace/, $(SRC_TRACE_NAME))
SRC_UTILS = $(addprefix src/utils/, $(SRC_UTILS_NAME))
SRC_MAIN = ./src/main.c

SRC = $(SRC_MAIN) $(SRC_CONTROL) $(SRC_PARSE) $(SRC_SCENE) $(SRC_TRACE) $(SRC_UTILS)
OBJ = $(SRC:.c=.o)

# .SUFFIXES : .c

# .c.o :
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all : $(NAME)

clean :
	$(MAKE) -C $(LIBDIR) clean;
	$(RM) $(OBJ)

fclean : clean
	$(MAKE) -C $(LIBDIR) fclean;
	$(MAKE) -C $(MLXDIR) clean;
	$(RM) $(NAME)

re : fclean all

bonus : all

$(NAME) : $(OBJ) $(MLXDIR)/$(MLX) $(LIBDIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(LIBFLAG) $(OBJ) $(INCLUDE) -o $(NAME)
	install_name_tool -change $(MLX) $(MLXDIR)/$(MLX) $(NAME)

$(MLXDIR)/$(MLX) :
	@$(MAKE) -C $(MLXDIR) all

$(LIBDIR)/$(LIBFT) :
	@$(MAKE) -C $(LIBDIR) all

.PHONY : all clean re ppm open run
