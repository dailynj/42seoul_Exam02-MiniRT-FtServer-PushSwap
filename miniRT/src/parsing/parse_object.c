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

int		sp_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;

	if (cmdlen(one_line) != 4)
		return (print_error("Error: sp 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (free_print_error(tmp, "Error : sphere point 오류\n"));
	if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL)
		return (free_print_error(tmp, "Error: split 오류!\n"));
	if (cmdlen(tmp2) != 3)
		return (free2_print_error(tmp, tmp2, "Error : sphere color 오류\n"));
	obj_add_back(&cntl->scene->world, object(SP, sphere(point3(
		a2f(tmp[0]), a2f(tmp[1]), a2f(tmp[2])), a2f(one_line[2])),
		color(a2f(tmp2[0]) / 255.0, a2f(tmp2[1]) / 255.0,
		a2f(tmp2[2]) / 255.0)));
	ft_free2(tmp, tmp2);
	return (1);
}

int		pl_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cmdlen(one_line) != 4)
		return (print_error("Error: pl 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (free_print_error(tmp, "Error : plane point 오류\n"));
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		return (free_print_error(tmp, "Error: split 오류!\n"));
	if (cmdlen(tmp2) != 3)
		return (free2_print_error(tmp, tmp2, "Error : plane normal 오류\n"));
	if ((tmp3 = ft_split_char(one_line[3], ',')) == NULL)
		return (free2_print_error(tmp, tmp2, "Error: split 오류!\n"));
	if (cmdlen(tmp3) != 3)
		return (free3_print_error(tmp, tmp2, tmp3, "Error : plane color 오류\n"));
	obj_add_back(&cntl->scene->world, object(PL,
	plane(point3(a2f(tmp[0]), a2f(tmp[1]), a2f(tmp[2])),
	v_unit(vec(a2f(tmp2[0]), a2f(tmp2[1]), a2f(tmp2[2])))),
	color(a2f(tmp3[0]) / 255.0, a2f(tmp3[1]) / 255.0, a2f(tmp3[2]) / 255.0)));
	ft_free3(tmp, tmp2, tmp3);
	return (1);
}

int		sq_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cmdlen(one_line) != 5)
		return (print_error("Error: sq 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (free_print_error(tmp, "Error : sq point 오류\n"));
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		return (free_print_error(tmp, "Error: split 오류!\n"));
	if (cmdlen(tmp2) != 3)
		return (free2_print_error(tmp, tmp2, "Error : sq normal 오류\n"));
	if ((tmp3 = ft_split_char(one_line[4], ',')) == NULL)
		return (free2_print_error(tmp, tmp2, "Error: split 오류!\n"));
	if (cmdlen(tmp3) != 3)
		return (free3_print_error(tmp, tmp2, tmp3, "Error : sq color 오류\n"));
	obj_add_back(&cntl->scene->world, object(SQ, square(point3(a2f(tmp[0]),
		a2f(tmp[1]), a2f(tmp[2])), v_unit(vec(a2f(tmp2[0]),
		a2f(tmp2[1]), a2f(tmp2[2]))), a2f(one_line[3])), color(
		a2f(tmp3[0]) / 255.0, a2f(tmp3[1]) / 255.0, a2f(tmp3[2]) / 255.0)));
	ft_free3(tmp, tmp2, tmp3);
	return (1);
}

int		cy_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;

	if (cmdlen(one_line) != 6)
		return (print_error("Error: cy 인수 개수 오류\n"));
	if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
		return (print_error("Error: split 오류!\n"));
	if (cmdlen(tmp) != 3)
		return (free_print_error(tmp, "Error : cy point 오류\n"));
	if ((tmp2 = ft_split_char(one_line[2], ',')) == NULL)
		return (free_print_error(tmp, "Error: split 오류!\n"));
	if (cmdlen(tmp2) != 3)
		return (free2_print_error(tmp, tmp2, "Error : cy normal 오류\n"));
	if ((tmp3 = ft_split_char(one_line[5], ',')) == NULL)
		return (free2_print_error(tmp, tmp2, "Error: split 오류!\n"));
	if (cmdlen(tmp3) != 3)
		return (free3_print_error(tmp, tmp2, tmp3, "Error : cy color 오류\n"));
	obj_add_back(&cntl->scene->world, object(CY, cylinder(point3(a2f(tmp[0]),
		a2f(tmp[1]), a2f(tmp[2])), a2f(one_line[3]), a2f(one_line[4]),
		v_unit(vec(a2f(tmp2[0]), a2f(tmp2[1]), a2f(tmp2[2])))), color(
		a2f(tmp3[0]) / 255.0, a2f(tmp3[1]) / 255.0, a2f(tmp3[2]) / 255.0)));
	ft_free3(tmp, tmp2, tmp3);
	return (1);
}
