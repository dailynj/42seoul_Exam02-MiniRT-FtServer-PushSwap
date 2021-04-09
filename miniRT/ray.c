/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:04:39 by najlee            #+#    #+#             */
/*   Updated: 2021/04/09 20:04:42 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// create ray
t_ray	ray(t_vector _orig, t_vector _dir)
{
	t_ray r;

	r.orig = _orig;
	r.dir = _dir;
	return (r);
}

// orig + t * dir 벡터를만들어주는 함수
t_vector    ray_at(t_ray ray, double t)
{
	t_vector out;

	out.x = ray.orig.x + ray.dir.x * t;
	out.y = ray.orig.y + ray.dir.y * t;
	out.z = ray.orig.z + ray.dir.z * t;
	return (out);
}
