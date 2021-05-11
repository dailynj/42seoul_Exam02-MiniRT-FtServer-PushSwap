/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 01:09:15 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		ft_atoi(char *str)
{
	int	minus;
	int	answer;
	int	i;

	i = 0;
	minus = 1;
	answer = 0;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (minus * answer);
}

double		ft_atof(char *str)
{
	double	answer;
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	answer = 0.0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot = 1;
		else if (str[i] >= '0' && str[i] <= '9' && dot == 0)
			answer = answer * 10 + str[i] - '0';
		else if (str[i] >= '0' && str[i] <= '9' && dot > 0)
		{
			answer = answer + (str[i] - '0') / ft_pow(10.0, dot);
			dot++;
		}
		else
			return (-1);
		i++;
	}
	return (answer);
}

double		ft_pow(double num, int len)
{
	double	answer;

	answer = 1.0;
	while (len--)
		answer *= num;
	return (answer);
}
