/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:05 by hyongti           #+#    #+#             */
/*   Updated: 2021/01/13 05:45:02 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_spot_light			*spot_light(t_point point, double ratio, t_color color)
{
	t_spot_light		*light;

	if (!(light = (t_spot_light *)malloc(sizeof(t_spot_light))))
		return (0);
	light->p = point;
	light->brightness = ratio;
	light->color = color;
	return (light);
}

t_parallel_light		*parallel_light(t_vec dir, t_color color)
{
	t_parallel_light	*sun;

	if (!(sun = (t_parallel_light *)malloc(sizeof(t_parallel_light))))
		return (0);
	sun->dir = dir;
	sun->albedo = color;
	return (sun);
}
