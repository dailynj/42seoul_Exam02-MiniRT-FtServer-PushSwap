/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:31 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:39 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		cmdlen(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int		print_error(char *str)
{
	printf("%s", str);
	return(0);
}

t_bool	check_rt(char *rtname)
{
	int	i;

	i = ft_strlen(rtname);
	if (!(rtname[--i] == 't' && rtname[--i] == 'r' && rtname[--i] == '.'))
		return (FALSE);
	return (TRUE);
}
