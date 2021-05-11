/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:36:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/15 08:33:40 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "utils.h"
# include "scene.h"
# include "mlx.h"

/*
** parsing
*/

t_vec	to_vec(char **data);
t_color	to_color(char **data);
t_scene	*read_rt(char *argv, void *mlx);
void	parse_rt(char *line, t_scene *scene);
void	parse_rt_bonus(char *line, t_scene *scene, void *mlx);
void	get_resolution(char *line, t_scene *scene);
void	get_ambient(char *line, t_scene *scene);
void	get_background(char *line, t_scene *scene, void *mlx);
void	get_parallel_light(char *line, t_scene *scene);
void	get_camera(char *line, t_scene *scene);
void	get_light(char *line, t_scene *scene);
void	get_sphere(char *line, t_scene *scene);
void	get_cylinder(char *line, t_scene *scene);
void	get_square(char *line, t_scene *scene);
void	get_plane(char *line, t_scene *scene);
void	get_triangle(char *line, t_scene *scene);
void	get_cone(char *line, t_scene *scene);
void	get_cube(char *line, t_scene *scene);
void	get_pyramid(char *line, t_scene *scene);

/*
**  error
*/

int		is_aligned(t_vec vec);
void	error_not_aligned(void);
void	malloc_error(void);
void	parse_error(void);
int		data_format_check(char **data);
int		albedo_range_check(char **data);
void	range_error(void);
int		file_type_check(char *line, char *type);

#endif
