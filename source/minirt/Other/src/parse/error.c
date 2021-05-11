/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:10:54 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 19:29:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		error_not_aligned(void)
{
	printf("VECTOR IS NOT AXIS-ALIGNED\n");
	exit(0);
}

void		malloc_error(void)
{
	printf("MEMORY ALLOCATION FAILED\n");
	printf("EXIT PROGRAM\n");
	exit(0);
}

void		parse_error(void)
{
	printf("WRONG DATA FORMAT\n");
	printf("EXIT PROGRAM\n");
	exit(0);
}

static int	sub_data_check(char *data)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(data, ',');
	if (split == NULL || data == NULL)
		return (0);
	while (ft_isdouble(split[i]) == 1)
		i++;
	if (split[i] == NULL)
	{
		free(split);
		return (1);
	}
	return (0);
}

int			data_format_check(char **data)
{
	int		i;
	double	d;

	i = 0;
	while (data[i])
	{
		if (ft_isdouble(data[i]) == 1)
		{
			d = ft_atod(data[i]);
			if (d < 0)
				return (0);
		}
		else if (ft_isdouble(data[i]) == 0)
		{
			if (sub_data_check(data[i]) == 0)
				return (0);
		}
		++i;
	}
	if (data[i] == NULL)
		return (1);
	return (0);
}
