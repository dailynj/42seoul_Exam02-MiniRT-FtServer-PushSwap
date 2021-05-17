/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:25 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		tr_parse(t_cntl *cntl, char **one_line)
{
	char	**tmp;
	char	**tmp2;
	char	**tmp3;
	char	**tmp4;

	if (cmdlen(one_line) != 5)
		return (print_error("Error: tr 인수 개수 오류\n"));
	if ((tmp = split_char_lencheck(one_line[1], 3)) == NULL)
		return (0);
	if ((tmp2 = split_char_lencheck(one_line[2], 3)) == NULL)
		return (0);
	if ((tmp3 = split_char_lencheck(one_line[3], 3)) == NULL)
		return (0);
	if ((tmp4 = split_char_lencheck(one_line[4], 3)) == NULL)
		return (0);
	obj_add_back(&cntl->scene->world, object(TR, triangle(point3(a2f(tmp[0]),
	a2f(tmp[1]), a2f(tmp[2])), point3(a2f(tmp2[0]), a2f(tmp2[1]),
	a2f(tmp2[2])), point3(a2f(tmp3[0]), a2f(tmp3[1]), a2f(tmp3[2]))),
	color(a2f(tmp4[0]) / 255.0, a2f(tmp4[1]) / 255.0, a2f(tmp4[2]) / 255.0)));
	ft_free3(tmp, tmp2, tmp3);
	ft_freeall(tmp4);
	return (1);
}

char	**split_char_lencheck(char *one_line, int num)
{
	char **tmp;

	if ((tmp = ft_split_char(one_line, ',')) == NULL)
	{
		printf("Error: split 오류!\n");
		return (NULL);
	}
	if (cmdlen(tmp) != num)
	{
		printf("Error : 인수의 개수가 잘못 들어왔습니다! \n");
		return (NULL);
	}
	return (tmp);
}
