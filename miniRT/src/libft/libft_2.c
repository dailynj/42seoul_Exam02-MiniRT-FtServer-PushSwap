/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 13:58:15 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double			a2f(char *str)
{
	double		answer;
	int			i;
	int			minus;
	int			dot;

	i = -1;
	minus = 1;
	dot = 0;
	answer = 0.0;
	if (str[++i] == '-')
		minus *= -1;
	else
		--i;
	while (str[++i] != '\0')
	{
		if (str[i] == '.')
			dot = 1;
		else if (str[i] >= '0' && str[i] <= '9' && dot == 0)
			answer = answer * 10 + str[i] - '0';
		else if (str[i] >= '0' && str[i] <= '9' && dot > 0)
			answer = answer + (str[i] - '0') / ft_pow(10.0, dot++);
		else
			print_exit("Error : a2f 에러\n");
	}
	return (minus * answer);
}

double			ft_pow(double num, int len)
{
	double		answer;

	answer = 1.0;
	while (len--)
		answer *= num;
	return (answer);
}

void			print_exit(char *str)
{
	printf("%s", str);
	exit(1);
}

void			ft_free3(char **tmp, char **tmp2, char **tmp3)
{
	ft_freeall(tmp);
	ft_freeall(tmp2);
	ft_freeall(tmp3);
}

void			ft_free2(char **tmp, char **tmp2)
{
	ft_freeall(tmp);
	ft_freeall(tmp2);
}
