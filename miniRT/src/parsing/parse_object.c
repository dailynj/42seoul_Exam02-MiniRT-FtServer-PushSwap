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
	{
		printf("Error: sp 인수 개수 오류\n");
		return (0);
	}
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
	{
		return (0);
	}
	if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL) ///////짜증...
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
	{
		return (0);
	}
	obj_add_back(
		&cntl->scene->world,
		object(SP,
				sphere(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])),
						ft_atof(one_line[2])),
				color(ft_atoi(tmp2[0]) / 255.0, ft_atoi(tmp2[1]) / 255.0, ft_atoi(tmp2[2]) / 255.0)));
	free(tmp);
	free(tmp2);
	return (1);
}
int	pl_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 4)
	{
		printf("Error: pl 인수 개수 오류\n");
		return (0);
	}
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
	{
		return (0);
	}
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
	{
		return (0);
	}
	if ((tmp3 = ft_split_char(one_line[3], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp3[0]) == -1 || ft_atoi(tmp3[1]) == -1 || ft_atoi(tmp3[2]) == -1)
	{
		return (0);
	}
	obj_add_back(
		&cntl->scene->world,
		object(PL,
				plane(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])),
						vec(ft_atoi(tmp2[0]), ft_atoi(tmp2[1]), ft_atoi(tmp2[2]))),
				color(ft_atoi(tmp3[0]) / 255.0, ft_atoi(tmp3[1]) / 255.0, ft_atoi(tmp3[2]) / 255.0)));
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (1);
}

int	sq_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 5)
	{
		printf("Error: sq 인수 개수 오류\n");
		return (0);
	}
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
	{
		return (0);
	}
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
	{
		return (0);
	}
	if ((tmp3 = ft_split_char(one_line[4], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp3[0]) == -1 || ft_atoi(tmp3[1]) == -1 || ft_atoi(tmp3[2]) == -1)
	{
		return (0);
	}
	obj_add_back(
		&cntl->scene->world,
		object(SQ,
				square(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])),
						vec(ft_atoi(tmp2[0]), ft_atoi(tmp2[1]), ft_atoi(tmp2[2])),
						ft_atof(one_line[3])),
				color(ft_atoi(tmp3[0]) / 255.0, ft_atoi(tmp3[1]) / 255.0, ft_atoi(tmp3[2]) / 255.0)));
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (1);
}

int	cy_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cal_cmd_len(one_line) != 6)
	{
		printf("Error: cy 인수 개수 오류\n");
		return (0);
	}
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
	{
		return (0);
	}
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
	{
		return (0);
	}
	if ((tmp3 = ft_split_char(one_line[5], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp3[0]) == -1 || ft_atoi(tmp3[1]) == -1 || ft_atoi(tmp3[2]) == -1)
	{
		return (0);
	}
	obj_add_back(
		&cntl->scene->world,
		object(CY,
				cylinder(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])),
						vec(ft_atoi(tmp2[0]), ft_atoi(tmp2[1]), ft_atoi(tmp2[2])),
						ft_atof(one_line[3]),
						ft_atof(one_line[3])),
				color(ft_atoi(tmp3[0]) / 255.0, ft_atoi(tmp3[1]) / 255.0, ft_atoi(tmp3[2]) / 255.0)));
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (1);
}

int	tr_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;
	char	**tmp4;

	if (cal_cmd_len(one_line) != 5)
	{
		printf("Error: tr 인수 개수 오류\n");
		return (0);
	}
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
	{
		return (0);
	}
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
	{
		return (0);
	}
	if ((tmp3 = ft_split_char(one_line[3], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp3[0]) == -1 || ft_atoi(tmp3[1]) == -1 || ft_atoi(tmp3[2]) == -1)
	{
		return (0);
	}
	if ((tmp4 = ft_split_char(one_line[4], ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (0);
	}
	if (ft_atoi(tmp4[0]) == -1 || ft_atoi(tmp4[1]) == -1 || ft_atoi(tmp4[2]) == -1)
	{
		return (0);
	}
	obj_add_back(
		&cntl->scene->world,
		object(TR,
				triangle(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])),
						point3(ft_atoi(tmp2[0]), ft_atoi(tmp2[1]), ft_atoi(tmp2[2])),
						point3(ft_atoi(tmp3[0]), ft_atoi(tmp3[1]), ft_atoi(tmp3[2]))),
				color(ft_atoi(tmp4[0]) / 255.0, ft_atoi(tmp4[1]) / 255.0, ft_atoi(tmp4[2]) / 255.0)));
	free(tmp);
	free(tmp2);
	free(tmp3);
	free(tmp4);
	return (1);
}
