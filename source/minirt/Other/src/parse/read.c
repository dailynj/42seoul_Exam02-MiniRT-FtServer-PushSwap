/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:35:09 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 05:08:19 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_scene		*read_rt(char *argv, void *mlx)
{
	t_scene	*scene;
	int		fd;
	int		rd;
	char	*line;

	if (!(scene = malloc(sizeof(t_scene))))
		exit(0);
	scene_init(scene);
	fd = open(argv, O_RDONLY);
	rd = 1;
	while (rd == 1)
	{
		rd = get_next_line(fd, &line);
		parse_rt(line, scene);
		parse_rt_bonus(line, scene, mlx);
		free(line);
	}
	return (scene);
}

void		parse_rt(char *line, t_scene *scene)
{
	if (ft_strnstr(line, "R", 1) != NULL)
		get_resolution(line + 1, scene);
	else if (ft_strnstr(line, "c ", 2) != NULL)
		get_camera(line + 2, scene);
	else if (ft_strnstr(line, "A ", 2) != NULL)
		get_ambient(line + 2, scene);
	else if (ft_strnstr(line, "l", 1) != NULL)
		get_light(line + 2, scene);
	else if (ft_strnstr(line, "sp", 2) != NULL)
		get_sphere(line + 2, scene);
	else if (ft_strnstr(line, "cy", 2) != NULL)
		get_cylinder(line + 2, scene);
	else if (ft_strnstr(line, "sq", 2) != NULL)
		get_square(line + 2, scene);
	else if (ft_strnstr(line, "pl", 2) != NULL)
		get_plane(line + 2, scene);
	else if (ft_strnstr(line, "tr", 2) != NULL)
		get_triangle(line + 2, scene);
}

void		parse_rt_bonus(char *line, t_scene *scene, void *mlx)
{
	if (ft_strnstr(line, "sun", 3) != NULL)
		get_parallel_light(line + 3, scene);
	else if (ft_strnstr(line, "co", 2) != NULL)
		get_cone(line + 2, scene);
	else if (ft_strnstr(line, "cu", 2) != NULL)
		get_cube(line + 2, scene);
	else if (ft_strnstr(line, "py", 2) != NULL)
		get_pyramid(line + 2, scene);
	else if (ft_strnstr(line, "BG", 2) != NULL)
		get_background(line + 2, scene, mlx);
}
