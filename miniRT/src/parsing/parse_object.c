/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:25 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	sp_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;

	if (cal_cmd_len(one_line) != 4)
		print_error("Error: sp 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL)
		print_error("Error: split 오류!\n");
	obj_add_back(
		&cntl->scene->world,
		object(SP,
				sphere(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
						ft_atof(one_line[2])),
				color(ft_atof(tmp2[0]) / 255.0, ft_atof(tmp2[1]) / 255.0, ft_atof(tmp2[2]) / 255.0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	return (1);
}
int	pl_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 4)
		print_error("Error: pl 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp3 = ft_split_char(one_line[3], ',')) == NULL)
		print_error("Error: split 오류!\n");
	obj_add_back(
		&cntl->scene->world,
		object(PL,
				plane(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
						vec_unit(vec(ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])))),
				color(ft_atof(tmp3[0]) / 255.0, ft_atof(tmp3[1]) / 255.0, ft_atof(tmp3[2]) / 255.0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	ft_freeall(tmp3);
	return (1);
}

int	sq_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 5)
		print_error("Error: sq 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp3 = ft_split_char(one_line[4], ',')) == NULL)
		print_error("Error: split 오류!\n");
	
	obj_add_back(
		&cntl->scene->world,
		object(SQ,
				square(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
						vec_unit(vec(ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2]))),
						ft_atof(one_line[3])),
				color(ft_atof(tmp3[0]) / 255.0, ft_atof(tmp3[1]) / 255.0, ft_atof(tmp3[2]) / 255.0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	ft_freeall(tmp3);
	return (1);
}

int	cy_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 6)
		print_error("Error: cy 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp3 = ft_split_char(one_line[5], ',')) == NULL)
		print_error("Error: split 오류!\n");
	obj_add_back(
		&cntl->scene->world,
		object(CY, cylinder(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
						ft_atof(one_line[3]), ft_atof(one_line[4]), 
						vec_unit(vec(ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])))), 
						color(ft_atof(tmp3[0]) / 255.0, ft_atof(tmp3[1]) / 255.0, ft_atof(tmp3[2]) / 255.0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	ft_freeall(tmp3);
	return (1);
}

int	tr_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;
	char	**tmp4;

	if (cal_cmd_len(one_line) != 5)
		print_error("Error: tr 인수 개수 오류\n");
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp3 = ft_split_char(one_line[3], ',')) == NULL)
		print_error("Error: split 오류!\n");
	if ((tmp4 = ft_split_char(one_line[4], ',')) == NULL)
		print_error("Error: split 오류!\n");
	obj_add_back(
		&cntl->scene->world,
		object(TR,
				triangle(point3(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])),
						point3(ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])),
						point3(ft_atof(tmp3[0]), ft_atof(tmp3[1]), ft_atof(tmp3[2]))),
				color(ft_atof(tmp4[0]) / 255.0, ft_atof(tmp4[1]) / 255.0, ft_atof(tmp4[2]) / 255.0)));
	ft_freeall(tmp);
	ft_freeall(tmp2);
	ft_freeall(tmp3);
	ft_freeall(tmp4);
	return (1);
}
