/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:22 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		parse_ral(t_cntl *cntl, char **ol)
{
	if (ol[0][0] == 'R')
	{
		if (r_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'A')
	{
		if (a_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'l')
	{
		if (l_parse(cntl, ol) == 0)
			return (0);
	}
	return (1);
}

int		parse_object(t_cntl *cntl, char **ol)
{
	if (ol[0][0] == 's' && ol[0][1] == 'p')
	{
		if (sp_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'p' && ol[0][1] == 'l')
	{
		if (pl_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 's' && ol[0][1] == 'q')
	{
		if (sq_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'c' && ol[0][1] == 'y')
	{
		if (cy_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 't' && ol[0][1] == 'r')
		if (tr_parse(cntl, ol) == 0)
			return (0);
	return (1);
}

int		parse_all2(t_cntl *cntl, char **ol)
{
	if ((!s_ncmp(ol[0], "sp", 2)) || (!s_ncmp(ol[0], "pl", 2)) ||
		(!s_ncmp(ol[0], "sq", 2)) || (!s_ncmp(ol[0], "cy", 2))
		|| (!s_ncmp(ol[0], "tr", 2)))
	{
		if (parse_object(cntl, ol) == 0)
			return (0);
	}
	else if ((ol[0][0] == 'R') || (ol[0][0] == 'A') || (ol[0][0] == 'l'))
		if (parse_ral(cntl, ol) == 0)
			return (0);
	return (1);
}

int		parsing_all(t_cntl *cntl, char **line, int cmd_len)
{
	int		i;
	char	**ol;
	int		cam_t;

	cam_t = 0;
	i = 0;
	while (i < cmd_len)
	{
		if ((ol = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if ((!s_ncmp(ol[0], "sp", 2)) || (!s_ncmp(ol[0], "pl", 2)) ||
		(!s_ncmp(ol[0], "sq", 2)) || (!s_ncmp(ol[0], "cy", 2)) ||
		(!s_ncmp(ol[0], "tr", 2)) || (ol[0][0] == 'R') ||
		(ol[0][0] == 'A') || (ol[0][0] == 'l'))
		{
			if (parse_all2(cntl, ol) == 0)
				return (0);
		}
		else if (ol[0][0] == 'c')
			if (c_parse(cntl, ol, cam_t++) == 0)
				return (0);
		ft_freeall(ol);
		i++;
	}
	return (1);
}
