/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:54:26 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:04:51 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double		deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

int			is_aligned(t_vec vec)
{
	if (fabs(vec.x) == 1 && fabs(vec.y) == 0 && fabs(vec.z) == 0)
		return (X);
	else if (fabs(vec.x) == 0 && fabs(vec.y) == 1 && fabs(vec.z) == 0)
		return (Y);
	else if (fabs(vec.x) == 0 && fabs(vec.y) == 0 && fabs(vec.z) == 1)
		return (Z);
	return (0);
}

double		random_double(void)
{
	return ((double)rand() / ((double)RAND_MAX + 1));
}

double		saturate(double value)
{
	if (value < 0)
		return (0);
	if (value > 1)
		return (1);
	return (value);
}

int			saturate_min_max_int(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
