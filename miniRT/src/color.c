/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:49:38 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 00:49:40 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// create color
t_color		color(double r, double g, double b)
{
	t_color c;

	c.x = r;
	c.y = g;
	c.z = b;
	return (c);
}

int write_color(int t, t_color pixel_color)
{
	return (t << 24 | (int)(pixel_color.x * 255) << 16 | (int)(pixel_color.y * 255) << 8 | (int)(pixel_color.z * 255));
}
