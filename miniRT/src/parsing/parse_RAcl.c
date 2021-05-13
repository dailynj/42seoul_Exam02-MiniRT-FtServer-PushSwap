/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_RAcl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:16 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	r_parse(t_cntl *cntl, char **one_line)
{
	if (cal_cmd_len(one_line) != 3)
	{
		printf("Error: R 인수 개수 오류\n");
		return (0);
	}
	cntl->scene->canvas.width = ft_atof(one_line[1]);
	cntl->scene->canvas.height = ft_atof(one_line[2]);
	cntl->scene->canvas.aspect_ratio =
		(double)ft_atof(one_line[1]) / ft_atof(one_line[2]);
	return (1);
}

int	a_parse(t_cntl *cntl, char **one_line)
{
	char	**amb;
	double	ratio;

	if (cal_cmd_len(one_line) != 3)
		return (print_error("Error: A 인수 개수 오류\n"));
	if ((amb = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	ratio = ft_atof(one_line[1]);
	cntl->scene->ambient = color(
		ratio * ft_atof(amb[0]), ratio * ft_atof(amb[1]), ratio * ft_atof(amb[2]));
	ft_freeall(amb);
	return (1);
}

int	c_parse(t_cntl *cntl, char **one_line, int idx)
{
	char		**tmp;
	char		**tmp2;
	t_camera	*tmp_c;
	int			fov;

	tmp_c = &(cntl->scene->camera_arr[idx]);
	if (cal_cmd_len(one_line) != 4)
		print_error("Error: camera 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	tmp_c->orig = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	write(1, &tmp_c->orig.x, 1);
	// printf("orig.x = %f, orig.y = %f, orig.z = %f", tmp_c->orig.x, tmp_c->orig.y, tmp_c->orig.z);
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	tmp_c->normal = vec(ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2]));
	ft_freeall(tmp);
	ft_freeall(tmp2);

	fov = ft_atof(one_line[3]);
	tmp_c->viewport_w = 2 * tan(fov / 360.0);
	tmp_c->viewport_h = tmp_c->viewport_w / cntl->scene->canvas.aspect_ratio;
	tmp_c->focal_len = 1.0; //고정
	tmp_c->horizontal =
		vec_mul_num(1, vec_unit(vec_cross(tmp_c->normal, vec(0, 1, 0))));
	tmp_c->vertical =
		vec_mul_num(1, vec_unit(vec_cross(tmp_c->horizontal, tmp_c->normal)));
	tmp_c->left_bottom =
		vec_minus(vec_minus(vec_minus(tmp_c->orig, vec_div(2, tmp_c->horizontal)),
							vec_div(2, tmp_c->vertical)),
					vec(0, 0, 1.0)); // 1.0 은 focal len
	return (1);
}

int	l_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;

	if (cal_cmd_len(one_line) != 4)
		print_error("Error: camera 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL)
		print_error("Error: split 오류!\n");
	obj_add_back(
		&cntl->scene->light,
		object(LIGHT_POINT,
				light_point(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
							color(ft_atof(tmp2[0]) / 255.0,
									ft_atof(tmp2[1]) / 255.0,
									ft_atof(tmp2[2]) / 255.0),
							ft_atof(one_line[2])),
				color(0, 0, 0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	return (1);
}
