/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:35:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/17 15:30:00 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_light(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	char	**p;
	double	ratio;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	p = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	ratio = ft_atod(data[1]);
	obj_add_back(&scene->objs,
		obj_new(SPOT_LIGHT, spot_light(to_vec(p), ratio, to_color(alb)), 0));
	free(data);
}

void	get_parallel_light(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	char	**ori;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	ori = ft_split(data[0], ',');
	alb = ft_split(data[1], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs, obj_new(PARELLEL_LIGHT,
		parallel_light(to_vec(ori), to_color(alb)), 0));
	free(data);
}

void	get_sphere(char *line, t_scene *scene)
{
	char	**data;
	char	**cen;
	double	radius;
	char	**alb;

	data = ft_split(line, ' ');
	if (data_format_check(data) == 0)
		parse_error();
	cen = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	if (albedo_range_check(alb) == 0)
		range_error();
	radius = ft_atod(data[1]);
	obj_add_back(&scene->objs,
		obj_new(SP, sphere(to_vec(cen), radius), texture(DEF, to_color(alb))));
	free(data);
}

void	get_cylinder(char *line, t_scene *scene)
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
	obj_add_back(&scene->objs, obj_new(CY,
	cylinder(to_vec(pos), to_vec(ori), ft_atod(data[2]), ft_atod(data[3])),
	texture(DEF, to_color(alb))));
	free(data);
}

void	get_square(char *line, t_scene *scene)
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
	alb = ft_split(data[3], ',');
	position = to_vec(pos);
	if (is_aligned(position) == 0)
		position = v_minus(position, vec(1e-6, 1e-6, 1e-6));
	if (is_aligned(to_vec(ori)) == 0)
		error_not_aligned();
	if (albedo_range_check(alb) == 0)
		range_error();
	obj_add_back(&scene->objs, obj_new(SQ,
		square(position, to_vec(ori), ft_atod(data[2])),
		texture(DEF, to_color(alb))));
	free(data);
}
