/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:35:13 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 19:44:30 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_resolution(char *line, t_scene *scene)
{
	int			width;
	int			height;
	char		**data;

	data = ft_split(line, ' ');
	width = ft_atoi(data[0]);
	height = ft_atoi(data[1]);
	if (width <= 0 || height <= 0)
	{
		printf("Errer\n");
		exit(0);
	}
	scene->canvas.width = width;
	scene->canvas.height = height;
	scene->canvas.ratio = (double)width / (double)height;
	free(data);
}

void	get_ambient(char *line, t_scene *scene)
{
	char		**data;
	double		strength;
	char		**alb;
	t_color		albedo;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	strength = ft_atod(data[0]);
	alb = ft_split(data[1], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, strength * 1.0 / 255.0);
	if (albedo_range_check(alb) == 0)
		range_error();
	scene->global.ambient = albedo;
	free(data);
}

void	get_background(char *line, t_scene *scene, void *mlx)
{
	char		**data;
	t_data		*bg;
	t_texture	*t;
	double		sidelen;

	if (!(bg = (t_data *)malloc(sizeof(t_data))))
		malloc_error();
	data = ft_split(line, ' ');
	bg->img = mlx_png_file_to_image(mlx, data[0], &bg->width, &bg->height);
	sidelen = ft_atod(data[1]);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bits_per_pixel,
								&bg->line_length, &bg->endian);
	t = texture_img(bg);
	scene->background = obj_new(IMAGE, cube(point(0, 0, 0), sidelen), t);
	free(data);
}

void	get_camera(char *line, t_scene *scene)
{
	char		**data;
	char		**lookfrom;
	char		**lookdir;
	t_camera	*cam;
	double		hfov;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	lookfrom = ft_split(data[0], ',');
	lookdir = ft_split(data[1], ',');
	hfov = ft_atod(data[2]);
	cam = cam_init(to_vec(lookfrom), to_vec(lookdir), hfov);
	set_cam(cam, scene);
	obj_add_back(&scene->cam_list,
				obj_new(CAM, cam, 0));
	free(data);
}
