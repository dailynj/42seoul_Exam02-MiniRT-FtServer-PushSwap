/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:53:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:18:49 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	color(double x, double y, double z)
{
	t_color	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

int		color_to_int(t_color pixel_color)
{
	int			r;
	int			g;
	int			b;

	r = (int)(255.999 * pixel_color.x);
	g = (int)(255.999 * pixel_color.y);
	b = (int)(255.999 * pixel_color.z);
	return ((r << 16) + (g << 8) + b);
}

int		get_r(int rgb)
{
	return (rgb >> 16 & 0xFF);
}

int		get_g(int rgb)
{
	return (rgb >> 8 & 0xFF);
}

int		get_b(int rgb)
{
	return (rgb & 0xFF);
}
