/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:35:13 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/17 15:27:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_plane(char *line, t_scene *scene)
{
	char	**data;
	char	**pos;
	char	**ori;
	char	**alb;
	t_point	position;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[2], ',');
	position = to_vec(pos);
	if (is_aligned(position) == 0)
		position = v_minus(position, vec(1e-6, 1e-6, 1e-6));
	if (is_aligned(to_vec(ori)) == 0)
		error_not_aligned();
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs, obj_new(PL,
		plane(position, to_vec(ori)), texture(DEF, to_color(alb))));
	free(data);
}

void	get_triangle(char *line, t_scene *scene)
{
	char	**data;
	char	**p1;
	char	**p2;
	char	**p3;
	char	**alb;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	p1 = ft_split(data[0], ',');
	p2 = ft_split(data[1], ',');
	p3 = ft_split(data[2], ',');
	alb = ft_split(data[3], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs, obj_new(TR,
		triangle(to_vec(p1), to_vec(p2), to_vec(p3)),
		texture(DEF, to_color(alb))));
	free(data);
}

void	get_cone(char *line, t_scene *scene)
{
	char	**data;
	char	**pos;
	char	**ori;
	char	**alb;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[4], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs, obj_new(CO,
		cone(to_vec(pos), to_vec(ori), ft_atod(data[2]), ft_atod(data[3])),
		texture(DEF, to_color(alb))));
	free(data);
}

void	get_cube(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	char	**pos;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	pos = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs,
	obj_new(CU, cube(to_vec(pos), ft_atod(data[1])),
	texture(DEF, to_color(alb))));
	free(data);
}

void	get_pyramid(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	char	**pos;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	pos = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs,
	obj_new(PY, pyramid(to_vec(pos), ft_atod(data[1])),
	texture(DEF, to_color(alb))));
	free(data);
}
