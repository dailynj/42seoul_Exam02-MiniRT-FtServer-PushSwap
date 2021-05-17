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
	if (cmdlen(one_line) != 3)
		return (print_error("Error: R 인수 개수 오류\n"));
	if (a2f(one_line[1]) > 2560.0 || a2f(one_line[2]) > 1440.0)
	{
		printf("Error : %f %f resolution의 가로 세로의 크기가 너무 큽니다\n",
		a2f(one_line[1]), a2f(one_line[2]));
		return (0);
	}
	cntl->scene->canv.wid = a2f(one_line[1]);
	cntl->scene->canv.heig = a2f(one_line[2]);
	cntl->scene->canv.aspect_ratio =
		(double)a2f(one_line[1]) / a2f(one_line[2]);
	return (1);
}

int	a_parse(t_cntl *cntl, char **one_line)
{
	char	**amb;
	double	ratio;

	if (cmdlen(one_line) != 3)
		return (print_error("Error: A 인수 개수 오류\n"));
	if ((amb = ft_split_char(one_line[2], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(amb) != 3)
		return (print_error("Error : color 인수의 개수가 잘못 들어왔습니다! \n"));
	ratio = a2f(one_line[1]);
	cntl->scene->ambient = color(
		ratio * a2f(amb[0]) / 255.0, ratio * a2f(amb[1]) / 255.0,
		ratio * a2f(amb[2]) / 255.0);
	ft_freeall(amb);
	return (1);
}

int	c_parse2(t_cntl *cntl, char **one_line, t_cam *tmp_c)
{
	int			fov;

	fov = a2f(one_line[3]);
	if (fov >= 180.0)
		return (print_error("Error: fov값은 180도 보다 작아야합니다!\n"));
	tmp_c->vp_w = 2 * tan((fov * 3.141592) / 360.0);
	tmp_c->vp_h = tmp_c->vp_w / cntl->scene->canv.aspect_ratio;
	tmp_c->focal_len = 1.0;
	tmp_c->horiz =
		v_mul_n(tmp_c->vp_w, v_unit(v_cr(tmp_c->normal, vec(0, 1, 0))));
	tmp_c->vertical =
		v_mul_n(tmp_c->vp_h, v_unit(v_cr(tmp_c->horiz, tmp_c->normal)));
	tmp_c->left_bottom =
		v_minus(v_minus(v_minus(tmp_c->orig, vec_div(2, tmp_c->horiz)),
		vec_div(2, tmp_c->vertical)), vec(0, 0, 1.0));
	return (1);
}

int	c_parse(t_cntl *cntl, char **one_line, int idx)
{
	char		**tmp;
	char		**tp2;
	t_cam		*tmp_c;

	tmp_c = &(cntl->scene->c_arr[idx]);
	if (cmdlen(one_line) != 4)
		return (print_error("Error: camera 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (print_error("Error : camera point 인수의 개수가 잘못 들어왔습니다! \n"));
	tmp_c->orig = vec(a2f(tmp[0]), a2f(tmp[1]), a2f(tmp[2]));
	if ((tp2 = ft_split_char(one_line[2], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tp2) != 3)
		return (print_error("Error : camera normal 인수의 개수가 잘못 들어왔습니다! \n"));
	tmp_c->normal = v_unit(vec(a2f(tp2[0]), a2f(tp2[1]), a2f(tp2[2])));
	ft_free2(tmp, tp2);
	return (c_parse2(cntl, one_line, tmp_c));
}

int	l_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;

	if (cmdlen(one_line) != 4)
		return (print_error("Error: camera 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (print_error("Error : light point 인수의 개수가 잘못 들어왔습니다! \n"));
	if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp2) != 3)
		return (print_error("Error : light color 인수의 개수가 잘못 들어왔습니다! \n"));
	obj_add_back(&cntl->scene->light, object(LIGHT_POINT,
	light_point(point3(a2f(tmp[0]), a2f(tmp[1]), a2f(tmp[2])),
	color(a2f(tmp2[0]) / 255.0, a2f(tmp2[1]) / 255.0,
	a2f(tmp2[2]) / 255.0), a2f(one_line[2])), color(0, 0, 0)));
	ft_free2(tmp, tmp2);
	return (1);
}
